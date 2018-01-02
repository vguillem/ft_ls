/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:48:22 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/08 13:46:49 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmpdest;
	const char	*tmpsrc;

	tmpdest = dest;
	tmpsrc = src;
	while (n-- > 0)
		*tmpdest++ = *tmpsrc++;
	return (dest);
}
