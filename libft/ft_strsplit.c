/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:28:57 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/10 10:54:24 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**ptr;

	if (!s)
		return (NULL);
	i = ft_countwords(s, c);
	if (!(ptr = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (!(ptr[i++] = ft_strsub(s, 0, j)))
			return (NULL);
		s += j;
		while (*s == c)
			s++;
	}
	return (ptr);
}
