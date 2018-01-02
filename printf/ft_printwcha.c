/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwcha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 08:44:39 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 09:35:14 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printwthree(int c, t_op *ops)
{
	int		a;
	int		b;
	int		d;

	a = (c >> 12) + 0xE0;
	b = ((c >> 6) & 0x3F) + 0x80;
	d = (c & 0x3F) + 0x80;
	ft_printprintf((char *)&a, ops, 1);
	ft_printprintf((char *)&b, ops, 1);
	ft_printprintf((char *)&d, ops, 1);
}

static void	ft_printwfour(int c, t_op *ops)
{
	int		a;
	int		b;
	int		d;

	a = (c >> 18) + 0xF0;
	b = ((c >> 12) & 0x3F) + 0x80;
	d = ((c >> 6) & 0x3F) + 0x80;
	c = (c & 0x3F) + 0x80;
	ft_printprintf((char *)&a, ops, 1);
	ft_printprintf((char *)&b, ops, 1);
	ft_printprintf((char *)&d, ops, 1);
	ft_printprintf((char *)&c, ops, 1);
}

void		ft_printprintfw(int c, t_op *ops)
{
	int		a;
	int		b;

	if (c <= 0x7F)
		ft_printprintf((char *)&c, ops, 1);
	else if (c <= 0x7FF)
	{
		a = (c >> 6) + 0xC0;
		b = (c & 0x3F) + 0x80;
		ft_printprintf((char *)&a, ops, 1);
		ft_printprintf((char *)&b, ops, 1);
	}
	else if (c <= 0xFFFF)
	{
		ft_printwthree(c, ops);
	}
	else if (c <= 0x10FFFF)
	{
		ft_printwfour(c, ops);
	}
}
