/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:22:18 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/30 13:06:05 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printdate(t_op *ops, va_list *ap)
{
	time_t	ref;
	char	*objref;

	ref = va_arg(*ap, time_t);
	objref = ctime(&ref);
	ft_printprintf(objref, ops, ft_strlen(objref));
}
