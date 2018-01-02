/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:57:59 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:14:27 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lsnotsamedater(t_bt *toplace, t_bt *ref)
{
	if (!ref->r)
		ref->r = toplace;
	else
	{
		ref = ref->r;
		while (ref->r && toplace->date != ref->date)
			ref = ref->r;
		if (toplace->date == ref->date)
			ft_sortsamedater(toplace, ref);
		else
			ref->r = toplace;
	}
}

void		ft_sortsamedater(t_bt *toplace, t_bt *ref)
{
	if (toplace->date != ref->date)
		ft_lsnotsamedater(toplace, ref);
	else
	{
		if (ft_strcmp(toplace->data, ref->data) > 0)
		{
			if (ref->l)
				ft_sortsamedater(toplace, ref->l);
			else
				ref->l = toplace;
		}
		else
		{
			if (ref->r)
				ft_sortsamedater(toplace, ref->r);
			else
				ref->r = toplace;
		}
	}
}

void		ft_sortbtdater(t_bt *toplace, t_bt *ref)
{
	if (toplace->date < ref->date)
	{
		if (ref->l)
			ft_sortbtdater(toplace, ref->l);
		else
			ref->l = toplace;
	}
	else if (toplace->date > ref->date)
	{
		if (ref->r)
			ft_sortbtdater(toplace, ref->r);
		else
			ref->r = toplace;
	}
	else if (toplace->date == ref->date)
	{
		ft_sortsamedater(toplace, ref);
	}
}
