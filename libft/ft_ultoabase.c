/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:21:52 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/25 15:21:54 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ulltoawrite(unsigned long long nb, int base, char *str, int i)
{
	while (nb > 0)
	{
		if (nb % base > 9)
			str[--i] = nb % base + 'A' - 10;
		else
			str[--i] = nb % base + '0';
		nb = nb / base;
	}
	return (str);
}

char		*ft_ulltoabase(unsigned long long nb, int base, int neg)
{
	int					i;
	unsigned long long	j;
	char				*result;

	if (base < 2 || base > 16 || neg < 0 || neg > 1)
		return (NULL);
	i = 0;
	j = nb;
	while (j > 0)
	{
		j = j / base;
		i++;
	}
	if (nb == 0)
		i++;
	result = (char *)ft_strnew(sizeof(char) * (i + neg));
	if (nb == 0)
		result[0] = '0';
	if (neg == 1)
		result[0] = '-';
	return (ft_ulltoawrite(nb, base, result, i + neg));
}
