/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:59:11 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/10 10:54:47 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*tmp;
	size_t			len;
	int				i;

	if (!s)
		return (NULL);
	while (*s && ft_iswhitespace(*s))
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	i = ft_strlen(s) - 1;
	len = ft_strlen(s);
	while (s[i] && ft_iswhitespace(s[i]) && len-- > 0)
		i--;
	tmp = ft_strsub(s, 0, len);
	if (!tmp)
		return (NULL);
	return (tmp);
}
