/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:21:45 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/03 13:41:53 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoabase(long long nb, int base)
{
	if (nb < 0)
		return (ft_ulltoabase((long)(nb * -1), base, 1));
	return (ft_ulltoabase((long)nb, base, 0));
}
