/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:29:54 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/10 10:57:50 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tmp = ft_strnew(sizeof(char) * ft_strlen(s));
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = f(s[i]);
		i++;
	}
	return (tmp);
}
