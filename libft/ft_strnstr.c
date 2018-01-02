/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:16:15 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/10 09:25:34 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *x, size_t len)
{
	int		i;
	int		y;
	size_t	j;

	i = 0;
	if (!(*x))
		return ((char *)src);
	while (src[i] && len-- > 0)
	{
		y = 0;
		if ((j = ft_strlen(x)) > len + 1)
			return (NULL);
		while (src[i + y] == x[y])
		{
			j--;
			if (j == 0)
				return ((char *)src + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
