/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:01 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/08 16:16:01 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmpdest;
	const char	*tmpsrc;

	tmpdest = dest;
	tmpsrc = src;
	if (tmpdest == tmpsrc)
		return (dest);
	if (tmpdest < tmpsrc)
		return (ft_memcpy(dest, src, n));
	tmpdest += n - 1;
	tmpsrc += n - 1;
	while (n-- > 0)
		*tmpdest-- = *tmpsrc--;
	return (dest);
}
