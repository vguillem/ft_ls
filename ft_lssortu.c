/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssortu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:27:32 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:22:11 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lsparseup(t_btp *btnew, t_btp *tmp2)
{
	btnew->next = tmp2->next;
	tmp2->next = btnew;
}

void		ft_parseur(t_btp *btnew, t_btp **ref)
{
	t_btp	*tmp;
	t_btp	*tmp2;

	tmp = *ref;
	tmp2 = NULL;
	while (tmp && btnew->bt->date > tmp->bt->date)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	while (tmp && btnew->bt->date == tmp->bt->date &&
				ft_strcmp(btnew->bt->data, tmp->bt->data) < 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp2)
		ft_lsparseup(btnew, tmp2);
	else
	{
		btnew->next = *ref;
		*ref = btnew;
	}
}

void		ft_parseu(t_btp *btnew, t_btp **ref)
{
	t_btp	*tmp;
	t_btp	*tmp2;

	tmp = *ref;
	tmp2 = NULL;
	while (tmp && btnew->bt->date < tmp->bt->date)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	while (tmp && btnew->bt->date == tmp->bt->date &&
				ft_strcmp(btnew->bt->data, tmp->bt->data) > 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp2)
		ft_lsparseup(btnew, tmp2);
	else
	{
		btnew->next = *ref;
		*ref = btnew;
	}
}
