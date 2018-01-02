/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:44:31 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/09 17:47:18 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int r;

	if (n >= 0)
		r = n;
	else
	{
		r = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (r != 0)
	{
		while (r > 9)
		{
			ft_putnbr_fd(r / 10, fd);
			r = r % 10;
		}
	}
	ft_putchar_fd(r % 10 + '0', fd);
}
