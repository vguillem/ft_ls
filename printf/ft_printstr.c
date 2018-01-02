/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 08:08:13 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 08:44:25 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printnotstr(t_op *ops)
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

static void	ft_printstrnotm(t_op *ops, char *str, int i)
{
	if (ops->zero == 1)
	{
		while (ops->min > i)
			ft_printprintf("0", ops, 1);
	}
	else
	{
		while (ops->min > i)
			ft_printprintf(" ", ops, 1);
	}
	ft_printprintf(str, ops, i);
}

void		ft_printstr(t_op *ops, va_list *ap)
{
	char	*str;
	int		i;

	str = va_arg(*ap, void *);
	if (!str)
	{
		ft_printnotstr(ops);
		return ;
	}
	i = ft_strlen(str);
	if (i > ops->pre && ops->pre != 1)
		i = ops->pre;
	if (ops->m == 1)
	{
		ft_printprintf(str, ops, i);
		while (ops->min > 0)
			ft_printprintf(" ", ops, 1);
	}
	else
		ft_printstrnotm(ops, str, i);
}
