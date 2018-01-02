/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:30:56 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 09:13:33 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printmin(t_op *ops, size_t i, size_t j)
{
	while (ops->min > (int)i)
	{
		if (ops->zero == 1 && j == 1)
			ft_printprintf("0", ops, 1);
		else
			ft_printprintf(" ", ops, 1);
	}
}

void	ft_signedops(t_op *ops)
{
	if (ops->conv == 'u')
	{
		if (ops->p == 1 || ops->space == 1)
			ops->min++;
		ops->p = 0;
		ops->space = 0;
	}
	if (ops->space == 1 && ops->neg == 0 && ops->p == 0)
	{
		ft_printprintf(" ", ops, 1);
		ops->min++;
	}
	else if (ops->neg == 0 && ops->p == 1)
	{
		ft_printprintf("+", ops, 1);
		ops->min++;
	}
	else if (ops->neg == 1)
	{
		ft_printprintf("-", ops, 1);
		ops->min++;
	}
}

void	ft_printopsm(char *str, t_op *ops, long long x)
{
	size_t			j;

	j = ft_strlen(str);
	ft_printops(ops, x);
	ft_signedops(ops);
	while (ops->pre-- > (int)j)
		ft_printprintf("0", ops, 1);
	ft_printprintf(str, ops, j);
	ft_printmin(ops, 0, 0);
}

void	ft_printopsnotm(char *str, t_op *ops, long long x)
{
	size_t			j;
	size_t			i;

	j = ft_strlen(str);
	if ((int)j < ops->pre)
		i = ops->pre;
	else
		i = j;
	if (ops->zero == 1)
	{
		ft_printops(ops, x);
		ft_signedops(ops);
	}
	ft_printmin(ops, i, 1);
	if (ops->zero == 0)
	{
		ft_printops(ops, x);
		ft_signedops(ops);
	}
	while (j < (unsigned int)ops->pre--)
		ft_printprintf("0", ops, 1);
	ft_printprintf(str, ops, ft_strlen(str));
}
