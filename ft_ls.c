/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:53:22 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:18:05 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lssort(int ops, t_btp *btp, t_bt *nbt)
{
	if (ops & OPS_F)
		ft_sortbtascii(nbt, btp->bt);
	else if (ops & OPS_R && ops & OPS_T)
		ft_sortbtdater(nbt, btp->bt);
	else if (ops & OPS_T)
		ft_sortbtdate(nbt, btp->bt);
	else if (ops & OPS_R)
		ft_sortbtasciir(nbt, btp->bt);
	else
		ft_sortbtascii(nbt, btp->bt);
}

static void	ft_lslect(struct dirent *lect, int *ops, t_btp *btp)
{
	t_bt	*nbt;

	nbt = NULL;
	if (!(lect->d_name[0] == '.' && !(*ops & OPS_A)))
	{
		*ops = *ops | OPS_N;
		nbt = ft_newbt(lect->d_name, btp, *ops);
	}
	if (nbt)
		ft_lssort(*ops, btp, nbt);
}

void		ft_ls(char *name, int *ops, t_btp *btp)
{
	DIR				*rep;
	struct dirent	*lect;

	if (*ops & OPS_D)
		ft_lsprintbt(btp->bt, *ops, btp);
	else
	{
		if (*ops & OPS_M && btp->bt->dir)
			ft_printf("%s:\n", btp->bt->data);
		if (!(rep = opendir(name)) && errno == EACCES)
			ft_dprintf(2, "ft_ls: %s: %s\n", name, strerror(errno));
		while (rep && (lect = readdir(rep)))
			ft_lslect(lect, ops, btp);
		if (rep)
			closedir(rep);
		if (*ops & OPS_RUP)
		{
			if (*ops & OPS_N)
				*ops -= OPS_N;
			if (btp->bt->r)
				ft_lsreadnbt(btp->bt->r, btp, ops);
			if (btp->bt->l)
				ft_lsreadnbt(btp->bt->l, btp, ops);
		}
	}
}
