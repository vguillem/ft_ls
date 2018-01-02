/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:42:33 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/09 17:32:30 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				i;
	int				neg;
	char			*ptr;
	unsigned int	nb;

	neg = 0;
	i = 0;
	nb = ABS(n);
	while (++i && nb > 9)
		nb /= 10;
	if (n < 0)
		neg = 1;
	if (!(ptr = ft_strnew(sizeof(char) * (i-- + neg))))
		return (NULL);
	if (neg)
		ptr[0] = '-';
	nb = ABS(n);
	while (nb > 9)
	{
		ptr[i-- + neg] = nb % 10 + '0';
		nb /= 10;
	}
	ptr[i + neg] = nb + '0';
	return (ptr);
}
