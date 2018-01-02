/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 08:15:18 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:14:13 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lsnotsamedate(t_bt *toplace, t_bt *ref)
{
	if (!ref->l)
		ref->l = toplace;
	else
	{
		ref = ref->l;
		while (ref->l && toplace->date != ref->date)
			ref = ref->l;
		if (toplace->date == ref->date)
			ft_sortsamedate(toplace, ref);
		else
			ref->l = toplace;
	}
}

void		ft_sortsamedate(t_bt *toplace, t_bt *ref)
{
	if (toplace->date != ref->date)
		ft_lsnotsamedate(toplace, ref);
	else
	{
		if (ft_strcmp(toplace->data, ref->data) < 0)
		{
			if (ref->l)
				ft_sortsamedate(toplace, ref->l);
			else
				ref->l = toplace;
		}
		else
		{
			if (ref->r)
				ft_sortsamedate(toplace, ref->r);
			else
				ref->r = toplace;
		}
	}
}

void		ft_sortbtdate(t_bt *toplace, t_bt *ref)
{
	if (toplace->date > ref->date)
	{
		if (ref->l)
			ft_sortbtdate(toplace, ref->l);
		else
			ref->l = toplace;
	}
	else if (toplace->date < ref->date)
	{
		if (ref->r)
			ft_sortbtdate(toplace, ref->r);
		else
			ref->r = toplace;
	}
	else if (toplace->date == ref->date)
	{
		ft_sortsamedate(toplace, ref);
	}
}
