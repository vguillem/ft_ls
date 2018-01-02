/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:54:19 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/29 10:54:20 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lssize(t_btp *origin, t_bt *bt)
{
	int		i;

	i = ft_strlen(bt->user);
	if (i > origin->su)
		origin->su = i;
	i = ft_strlen(bt->grp);
	if (i > origin->sg)
		origin->sg = i;
	i = ft_nbrlen(bt->nlink, 10);
	if (i > origin->sl)
		origin->sl = i;
	i = ft_nbrlen(bt->size, 10);
	if (i > origin->sp)
		origin->sp = i;
}
