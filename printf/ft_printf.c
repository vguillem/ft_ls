/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:54:08 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 10:21:30 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printprintf(const char *str, t_op *ops, int len)
{
	static char	buf[BUFF_SIZE];
	static int	i = 0;

	if (i == 0)
		ft_memset(buf, 0, BUFF_SIZE);
	if (i + len > BUFF_SIZE)
	{
		write(ops->fd, buf, i);
		i = 0;
		write(ops->fd, str, len);
	}
	else if (len != 0)
	{
		ft_strncpy(buf + i, str, len);
		i += len;
	}
	ops->nbpr += len;
	ops->min -= len;
	if (ops->end == 1)
	{
		write(ops->fd, buf, i);
		i = 0;
	}
}

static void	ft_initop(t_op *ops)
{
	ops->m = 0;
	ops->p = 0;
	ops->zero = 0;
	ops->space = 0;
	ops->htag = 0;
	ops->min = 0;
	ops->size = 0;
	ops->pre = 1;
	ops->mpre = 0;
	ops->conv = 0;
	ops->nboptions = 0;
	ops->neg = 0;
}

int			ft_printf(const char *str, ...)
{
	t_op	ops;
	va_list	ap;
	size_t	i;

	va_start(ap, str);
	i = 0;
	ops.fd = 1;
	ops.end = 0;
	ops.nbpr = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ft_printprintf(str + i++, &ops, 1);
		if (str[i] == '%')
		{
			ft_initop(&ops);
			i += 1 + ft_options(&ops, str + i + 1, &ap);
			if (str[i])
				i = i + ft_conv(&ops, str[i], &ap);
		}
	}
	ops.end = 1;
	ft_printprintf(0, &ops, 0);
	va_end(ap);
	return (ops.nbpr);
}

int			ft_dprintf(int fd, const char *str, ...)
{
	t_op	ops;
	va_list	ap;
	size_t	i;

	va_start(ap, str);
	i = 0;
	ops.fd = fd;
	ops.end = 0;
	ops.nbpr = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ft_printprintf(str + i++, &ops, 1);
		if (str[i] == '%')
		{
			ft_initop(&ops);
			i += 1 + ft_options(&ops, str + i + 1, &ap);
			if (str[i])
				i = i + ft_conv(&ops, str[i], &ap);
		}
	}
	ops.end = 1;
	ft_printprintf(0, &ops, 0);
	va_end(ap);
	return (ops.nbpr);
}
