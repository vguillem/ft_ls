/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsreadbt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:54:01 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:25:01 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lspath(char *buf, char *origin, char *name)
{
	buf[0] = 0;
	if (origin)
	{
		ft_strcat(buf, origin);
		ft_strcat(buf, "/");
	}
	if (name)
		ft_strcat(buf, name);
}

static int	ft_lsisfolder(t_btp *origin, t_bt *bt, int *ops)
{
	t_btp	*tmp;
	char	buf[PATH_MAX];

	if (ft_strcmp(".", bt->data) == 0)
		return (0);
	if (ft_strcmp("..", bt->data) == 0)
		return (0);
	ft_lspath(buf, origin->bt->data, bt->data);
	*ops = (OPS_N | *ops);
	if (bt->dir)
	{
		*ops = (OPS_M | *ops);
		tmp = ft_newbtp(buf, *ops);
		if (!tmp)
			return (0);
		tmp->next = origin->next;
		origin->next = tmp;
		return (1);
	}
	return (0);
}

void		ft_lsreadnbt(t_bt *bt, t_btp *origin, int *ops)
{
	if (bt->r)
		ft_lsreadnbt(bt->r, origin, ops);
	if (!(bt->data[0] == '.' && !(*ops & OPS_A)))
		ft_lsisfolder(origin, bt, ops);
	if (bt->l)
		ft_lsreadnbt(bt->l, origin, ops);
}

void		ft_lsreadprint(t_bt *bt, int ops, t_btp *ref)
{
	if (bt->l)
		ft_lsreadprint(bt->l, ops, ref);
	if (!(bt->data[0] == '.' && !(ops & OPS_A)))
		ft_lsprintbt(bt, ops, ref);
	if (bt->r)
		ft_lsreadprint(bt->r, ops, ref);
	ft_memdel((void **)&bt);
}
