/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 08:07:16 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 09:22:03 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printptrm(t_op *ops, char *tmp, int j)
{
	ft_printprintf("0x", ops, 2);
	while (ops->pre-- > (j + 2))
		ft_printprintf("0", ops, 1);
	ft_printprintf(tmp, ops, j);
	while (ops->min > (j + 2))
		ft_printprintf(" ", ops, 1);
}

static void	ft_printptrnotm(t_op *ops, char *tmp, int j)
{
	int	i;

	if (ops->pre > j)
		i = ops->pre;
	else
		i = j;
	while (ops->min > (i + 2))
		ft_printprintf(" ", ops, 1);
	ft_printprintf("0x", ops, 2);
	while (ops->pre-- > (j))
		ft_printprintf("0", ops, 1);
	ft_printprintf(tmp, ops, j);
}

static void	ft_printnotptr(t_op *ops)
{
	if (ops->m == 0 && ops->zero == 0)
	{
		while (ops->min > (2 + ops->pre))
			ft_printprintf(" ", ops, 1);
		ft_printprintf("0x", ops, 2);
		while (ops->pre-- > 0)
			ft_printprintf("0", ops, 1);
	}
	else
	{
		ft_printprintf("0x", ops, 2);
		while (ops->pre-- > 0)
			ft_printprintf("0", ops, 1);
		while (ops->min > 0)
		{
			if (ops->zero == 0)
				ft_printprintf(" ", ops, 1);
			if (ops->zero == 1)
				ft_printprintf("0", ops, 1);
		}
	}
}

void		ft_printptr(t_op *ops, va_list *ap)
{
	void	*ptr;
	char	*tmp;
	int		j;

	ptr = va_arg(*ap, void *);
	if (ptr)
	{
		if (ops->pre == 0)
			ft_printprintf("0", ops, 1);
		else
		{
			tmp = ft_tolowers(ft_ulltoabase((unsigned long)ptr, 16, 0));
			j = ft_strlen(tmp);
			if (ops->m == 1)
				ft_printptrm(ops, tmp, j);
			else if (ops->m == 0)
				ft_printptrnotm(ops, tmp, j);
			ft_memdel((void **)&tmp);
		}
	}
	else
		ft_printnotptr(ops);
}
