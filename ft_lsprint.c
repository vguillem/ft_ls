/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:53:55 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:24:29 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lsprintdate(time_t ref)
{
	char	*objref;
	time_t	date;
	int		a;

	objref = ctime(&ref);
	a = ft_atoi(objref + 20);
	date = time(0) - 15768000;
	ft_printf("%.7s", objref + 4);
	if (ref < date)
	{
		ft_printf(" %d ", a);
	}
	else
	{
		date = time(0) + 3600;
		if (ref > date)
		{
			ft_printf(" %d ", a);
		}
		else
			ft_printf("%.5s ", objref + 11);
	}
}

void		ft_lsprint(t_btp *btp, int ops)
{
	if (btp->bt->dir)
	{
		if (ops & OPS_L && (ops & OPS_A || ops & OPS_N))
			ft_printf("total %u\n", btp->totalblock);
	}
	else if (!btp->bt->l && !btp->bt->r)
		ft_lsprintbt(btp->bt, ops, btp);
	if (btp->bt->l)
		ft_lsreadprint(btp->bt->l, ops, btp);
	if (btp->bt->r)
		ft_lsreadprint(btp->bt->r, ops, btp);
	if ((btp->next && btp->next->bt->dir) && !(ops & OPS_D))
		ft_putchar('\n');
}

void		ft_lsprintbt(t_bt *bt, int ops, t_btp *ref)
{
	if (ops & OPS_L)
	{
		ft_lsacces(bt);
		ft_printf(" %*u ", ref->sl, bt->st.st_nlink);
		ft_printf("%-*s  %-*s  ", ref->su, bt->user, ref->sg, bt->grp);
		if (S_ISBLK(bt->st.st_mode) || S_ISCHR(bt->st.st_mode))
			ft_printf("%3d, %3d ", MAXI(bt->st.st_rdev), MINI(bt->st.st_rdev));
		else
			ft_printf("%*u ", ref->sp, bt->st.st_size);
		ft_lsprintdate(bt->date);
		if (bt->link[0])
			ft_printf("%s -> %s\n", bt->data, bt->link);
		else
			ft_printf("%s\n", bt->data);
	}
	else
		ft_printf("%s\n", bt->data);
}

void		ft_lsprintbadop(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ft_ls [-Radflrtu] [file ...]\n");
	exit(1);
}

void		ft_lsprintbadname(char *str)
{
	ft_printf("ft_ls: cannot access '%s': No such file or directory\n", str);
}
