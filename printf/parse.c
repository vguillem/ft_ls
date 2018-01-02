/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 08:37:17 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/16 10:22:05 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_optionssize(t_op *ops, const char *str, size_t i)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		ops->size = SIZE_HH;
		i += 2;
	}
	else if (str[i] == 'h' && ++i > 0)
		ops->size = SIZE_H;
	else if (str[i] == 'l' && str[i + 1] == 'l')
	{
		ops->size = SIZE_LL;
		i += 2;
	}
	else if (str[i] == 'l' && ++i > 0)
		ops->size = SIZE_L;
	else if (str[i] == 'j' && ++i > 0)
		ops->size = SIZE_J;
	else if (str[i] == 'z' && ++i > 0)
		ops->size = SIZE_Z;
	return (i);
}

static size_t	ft_opdigit(t_op *ops, const char *str, size_t i, va_list *ap)
{
	while (str[i] == '*' || ft_isdigit(str[i]))
	{
		ops->mpre = 1;
		if (str[i] == '*' && ++i > 0)
			ops->min = va_arg(*ap, int);
		else
		{
			ops->min = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*' && ++i > 0)
			ops->pre = va_arg(*ap, int);
		else
		{
			ops->pre = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	return (i);
}

static void		ft_flags(t_op *ops, const char *str, int i)
{
	if (str[i] == '#')
		ops->htag = 1;
	if (str[i] == '-')
		ops->m = 1;
	if (str[i] == '+')
		ops->p = 1;
	if (str[i] == ' ')
		ops->space = 1;
	if (str[i] == '0')
		ops->zero = 1;
}

size_t			ft_options(t_op *ops, const char *str, va_list *ap)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '#' || str[i] == '-' || str[i] == '+' ||
				str[i] == '0' || str[i] == ' '))
	{
		ft_flags(ops, str, i);
		i++;
	}
	i = ft_opdigit(ops, str, i, ap);
	i = ft_optionssize(ops, str, i);
	if (ops->pre < 0)
		ops->pre = 1;
	if (ops->min < 0)
	{
		ops->m = 1;
		ops->min = ops->min * -1;
	}
	return (i);
}

int				ft_conv(t_op *ops, char c, va_list *ap)
{
	if (ops->size == SIZE_L && (c == 's' || c == 'c'))
		c = c - 'a' + 'A';
	ops->conv = c;
	if (c == 'd' || c == 'i')
		ft_printint(ops, ap);
	else if (c == 'S')
		ft_printwstr(ops, ap);
	else if (c == 's')
		ft_printstr(ops, ap);
	else if (c == 'o')
		ft_printuint(ops, ap, 8);
	else if (c == 'u')
		ft_printuint(ops, ap, 10);
	else if (c == 'x' || c == 'X')
		ft_printuint(ops, ap, 16);
	else if (c == 'U' || c == 'O' || c == 'D')
		ft_printoud(ops, ap);
	else if (c == 'p')
		ft_printptr(ops, ap);
	else if (c == 't')
		ft_printdate(ops, ap);
	else
		ft_printcha(ops, ap);
	return (1);
}
