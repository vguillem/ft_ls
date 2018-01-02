/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:30:02 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/29 16:44:54 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sortbtasciir(t_bt *toplace, t_bt *ref)
{
	if (ft_strcmp(toplace->data, ref->data) < 0)
	{
		if (ref->r)
			ft_sortbtasciir(toplace, ref->r);
		else
			ref->r = toplace;
	}
	else
	{
		if (ref->l)
			ft_sortbtasciir(toplace, ref->l);
		else
			ref->l = toplace;
	}
}

void	ft_sortbtascii(t_bt *toplace, t_bt *ref)
{
	if (ft_strcmp(toplace->data, ref->data) >= 0)
	{
		if (ref->r)
			ft_sortbtascii(toplace, ref->r);
		else
			ref->r = toplace;
	}
	else
	{
		if (ref->l)
			ft_sortbtascii(toplace, ref->l);
		else
			ref->l = toplace;
	}
}

void	ft_parseasciir(t_btp *btnew, t_btp **ref)
{
	t_btp	*tmp;
	t_btp	*tmp2;

	if (ft_strcmp(btnew->bt->data, (*ref)->bt->data) > 0)
	{
		btnew->next = *ref;
		*ref = btnew;
	}
	else
	{
		tmp = (*ref)->next;
		tmp2 = *ref;
		while (tmp && ft_strcmp(btnew->bt->data, tmp->bt->data) <= 0)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		btnew->next = tmp2->next;
		tmp2->next = btnew;
	}
}

void	ft_parseascii(t_btp *btnew, t_btp **ref)
{
	t_btp	*tmp;
	t_btp	*tmp2;

	if (ft_strcmp(btnew->bt->data, (*ref)->bt->data) < 0)
	{
		btnew->next = *ref;
		*ref = btnew;
	}
	else
	{
		tmp = (*ref)->next;
		tmp2 = *ref;
		while (tmp && ft_strcmp(btnew->bt->data, tmp->bt->data) >= 0)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		btnew->next = tmp2->next;
		tmp2->next = btnew;
	}
}
