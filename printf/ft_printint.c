/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:54:03 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/10 09:12:12 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printopspms(unsigned long long int i, t_op *ops, char *str)
{
	if (ops->pre != 1)
		ops->zero = 0;
	if (ops->htag == 1 && (ops->conv == 'x' || ops->conv == 'X') && i != 0)
		ops->min -= 2;
	if (ops->htag == 1 && (ops->conv == 'o' || ops->conv == 'O') && i != 0)
		ops->min -= 1;
	if (ops->neg == 1 || ops->p == 1 || ops->space == 1)
		ops->min -= 1;
	if (ops->pre == 0 && i == 0)
		str[0] = 0;
	if (ops->m == 1)
		ft_printopsm(str, ops, i);
	else if (ops->m == 0)
		ft_printopsnotm(str, ops, i);
	ft_memdel((void **)&str);
}

void	ft_printint(t_op *ops, va_list *ap)
{
	long long int			i;
	unsigned long long int	j;
	char					*str;

	if (ops->size == SIZE_HH)
		i = (char)va_arg(*ap, long long int);
	else if (ops->size == SIZE_H)
		i = (short int)va_arg(*ap, long long int);
	else if (ops->size == SIZE_LL)
		i = (long long int)va_arg(*ap, long long int);
	else if (ops->size == SIZE_L)
		i = (long int)va_arg(*ap, long long int);
	else if (ops->size == SIZE_J)
		i = (intmax_t)va_arg(*ap, long long int);
	else if (ops->size == SIZE_Z)
		i = (size_t)va_arg(*ap, long long int);
	else
		i = (int)va_arg(*ap, long long int);
	j = ft_topos(i);
	if (i < 0)
		ops->neg = 1;
	str = ft_ulltoabase(j, 10, 0);
	ft_printopspms(j, ops, str);
}

void	ft_printuint(t_op *ops, va_list *ap, int base)
{
	unsigned long long int	i;
	char					*str;

	if (ops->size == SIZE_HH)
		i = (unsigned char)va_arg(*ap, unsigned long long int);
	else if (ops->size == SIZE_H)
		i = (unsigned short)va_arg(*ap, unsigned long long int);
	else if (ops->size == SIZE_L)
		i = (unsigned long long)va_arg(*ap, unsigned long long int);
	else if (ops->size == SIZE_LL)
		i = (unsigned long)va_arg(*ap, unsigned long long int);
	else if (ops->size == SIZE_J)
		i = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (ops->size == SIZE_Z)
		i = (size_t)va_arg(*ap, unsigned long long int);
	else
		i = (unsigned int)va_arg(*ap, unsigned long long int);
	str = ft_ulltoabase(i, base, 0);
	if (ops->conv == 'x' || ops->conv == 'o')
		str = ft_tolowers(str);
	ft_printopspms(i, ops, str);
}

void	ft_printoud(t_op *ops, va_list *ap)
{
	long int			i;
	unsigned long int	j;
	char				*str;

	i = (long int)va_arg(*ap, long int);
	if (ops->conv == 'U')
		str = ft_ulltoabase(i, 10, 0);
	if (ops->conv == 'O')
		str = ft_ulltoabase(i, 8, 0);
	if (ops->conv == 'D')
	{
		j = ft_topos(i);
		if (i < 0)
			ops->neg = 1;
		str = ft_ulltoabase(j, 10, 0);
	}
	ft_printopspms(i, ops, str);
}
