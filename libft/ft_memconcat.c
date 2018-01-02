/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:16:50 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/03 08:13:54 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memconcat(void *s1, void *s2, int sizes1, int sizes2)
{
	void	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		tmp = ft_realloc(s1, sizes1, sizes2);
	else
		tmp = ft_memalloc(sizes2);
	if (s2)
		ft_memmove(tmp + sizes1, s2, sizes2);
	return (tmp);
}
