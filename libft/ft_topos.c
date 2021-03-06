/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:29:53 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/09 15:30:02 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_topos(long long i)
{
	unsigned long long	j;

	if (i >= 0)
		j = i;
	else
		j = i * -1;
	return (j);
}
