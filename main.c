/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:54:52 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/29 10:54:53 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			ops;
	t_btp		*btp;
	t_btp		*tmp;

	ops = 0;
	btp = NULL;
	ft_lsparse(ac, av, &btp, &ops);
	tmp = btp;
	while (tmp)
	{
		ft_ls(tmp->bt->data, &ops, tmp);
		ft_lsprint(tmp, ops);
		tmp = tmp->next;
		ft_memdel((void **)&(btp->bt));
		ft_memdel((void **)&btp);
		btp = tmp;
	}
}
