/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:54:16 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/16 10:23:06 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printcham(t_op *ops, int r)
{
	if (ops->conv == 'C')
		ft_printprintfw(r, ops);
	else
		ft_printprintf((char *)&r, ops, 1);
	while (ops->min > 0)
		ft_printprintf(" ", ops, 1);
}

static void	ft_printchanotm(t_op *ops, int r)
{
	while (ops->min > 1)
	{
		if (ops->zero == 1)
			ft_printprintf("0", ops, 1);
		else
			ft_printprintf(" ", ops, 1);
	}
	if (ops->conv == 'C')
		ft_printprintfw(r, ops);
	else
		ft_printprintf((char *)&r, ops, 1);
}

void		ft_printcha(t_op *ops, va_list *ap)
{
	int	r;

	if (ops->conv != 'c' && ops->conv != 'C')
		r = ops->conv;
	else
		r = va_arg(*ap, int);
	if (ops->m == 1)
		ft_printcham(ops, r);
	else
		ft_printchanotm(ops, r);
}
