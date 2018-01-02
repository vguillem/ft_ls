/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhtag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:58:22 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 09:10:16 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_htagmin(t_op *ops)
{
	if (ops->conv == 'x' || ops->conv == 'X')
		ops->min += 2;
	if (ops->conv == 'O' || ops->conv == 'o')
		ops->min += 1;
}

void	ft_printhtag(t_op *ops)
{
	if (ops->conv == 'O' && (ops->pre == 1 || ops->pre == 0))
		ft_printprintf("0", ops, 1);
	if (ops->conv == 'o' && (ops->pre == 1 || ops->pre == 0))
		ft_printprintf("0", ops, 1);
	if (ops->conv == 'x')
		ft_printprintf("0x", ops, 2);
	if (ops->conv == 'X')
		ft_printprintf("0X", ops, 2);
	ft_htagmin(ops);
}

void	ft_printops(t_op *ops, long long int i)
{
	if (ops->conv != 'x' && ops->conv != 'o'
		&& ops->conv != 'X' && ops->conv != 'O')
		ops->htag = 0;
	else
	{
		ops->p = 0;
		ops->space = 0;
	}
	if (ops->htag == 1 && i != 0)
		ft_printhtag(ops);
	else if (ops->htag == 1 && ops->pre == 0)
	{
		if (ops->conv == 'o' || ops->conv == 'O')
		{
			ft_printprintf("0", ops, 1);
			ft_htagmin(ops);
		}
	}
}
