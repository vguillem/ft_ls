/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 08:04:42 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 09:40:06 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_wsizep(wchar_t *t)
{
	int		i;
	int		r;

	i = -1;
	r = 0;
	while (t[++i] != 0)
	{
		if (t[i] <= 0x7F)
			r++;
		else if (t[i] <= 0x7FF)
			r += 2;
		else if (t[i] <= 0xFFFF)
			r += 3;
		else if (t[i] <= 0x10FFFF)
			r += 4;
	}
	return (r);
}

static void	ft_printnotwstr(t_op *ops)
{
	if (ops->pre == 0)
	{
		while (ops->min > 0)
		{
			if (ops->zero == 1)
				ft_printprintf("0", ops, 1);
			if (ops->zero == 0)
				ft_printprintf(" ", ops, 1);
		}
	}
	else
	{
		while (ops->min > 6)
		{
			if (ops->zero == 1)
				ft_printprintf("0", ops, 1);
			if (ops->zero == 0)
				ft_printprintf(" ", ops, 1);
		}
		ft_printprintf("(null)", ops, 6);
	}
}

void		ft_printwstrnotm(t_op *ops, wchar_t *str, int i, int len)
{
	int	j;

	if (ops->zero == 1)
	{
		while (ops->min > len)
			ft_printprintf("0", ops, 1);
	}
	else
	{
		while (ops->min > len)
			ft_printprintf(" ", ops, 1);
	}
	j = 0;
	while (j < i)
		ft_printprintfw(str[j++], ops);
}

void		ft_printwstr(t_op *ops, va_list *ap)
{
	wchar_t	*str;
	int		i;
	int		j;
	int		len;

	str = va_arg(*ap, void *);
	if (!str)
	{
		ft_printnotwstr(ops);
		return ;
	}
	i = ft_wstrlen(str);
	len = ft_wsizep(str);
	if (ops->pre == 0)
		i = 0;
	if (ops->m == 1)
	{
		j = 0;
		while (j < i)
			ft_printprintfw(str[j++], ops);
		while (ops->min > 0)
			ft_printprintf(" ", ops, 1);
	}
	else
		ft_printwstrnotm(ops, str, i, len);
}
