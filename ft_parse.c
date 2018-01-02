/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:54:26 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:22:51 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_lsparsopb(char *str, int *ops)
{
	if (*str == 'l')
		*ops = (OPS_L | *ops);
	else if (*str == 'r')
		*ops = (OPS_R | *ops);
	else if (*str == 'R')
		*ops = (OPS_RUP | *ops);
	else if (*str == 't')
		*ops = (OPS_T | *ops);
	else if (*str == 'd')
		*ops = (OPS_D | *ops);
	else if (*str == 'f')
		*ops = (OPS_F | OPS_A | *ops);
	else if (*str == 'a')
		*ops = (OPS_A | *ops);
	else if (*str == 'g')
		*ops = (OPS_G | *ops);
	else if (*str == '1')
		*ops = (OPS_UN | *ops);
	else if (*str == 'u')
		*ops = (OPS_U | *ops);
	else
		return (0);
	return (1);
}

static void	ft_lsparsop(char *str, int *ops, int *j)
{
	while (*++str)
	{
		if (ft_lsparsopb(str, ops))
			;
		else if (*str == '-')
		{
			*j = 0;
			if (*(str + 1))
				ft_lsprintbadop(*str);
		}
		else
			ft_lsprintbadop(*str);
	}
}

static void	ft_parsjoin(t_btp **file, t_btp **folder, int j, int ops)
{
	t_btp	*tmp;

	tmp = *file;
	if (!tmp)
		*file = *folder;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = *folder;
	}
	if (!*file && j == 0)
		*file = ft_newbtp(".", ops);
}

static int	ft_lsparsname(char *str, t_btp **f, int ops)
{
	t_btp	*new;
	t_btp	*tmp;

	if (!(new = ft_newbtp(str, ops)))
		return (0);
	if (!*f)
		*f = new;
	else if (ops & OPS_F)
	{
		tmp = *f;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if ((ops & OPS_T) && (OPS_R & ops))
		ft_parseur(new, f);
	else if (ops & OPS_T)
		ft_parseu(new, f);
	else if (ops & OPS_R)
		ft_parseasciir(new, f);
	else
		ft_parseascii(new, f);
	return (1);
}

void		ft_lsparse(int ac, char **av, t_btp **bt, int *ops)
{
	int		i;
	DIR		*directory;
	t_btp	*folder;
	int		j;

	folder = NULL;
	i = 0;
	j = 1;
	while (++i < ac && av[i] && av[i][0] == '-' && j && av[i][1])
		ft_lsparsop(av[i], ops, &j);
	if ((j = ac - i) > 1)
		*ops = (*ops | OPS_M);
	while (i < ac)
	{
		if ((directory = opendir(av[i])) != NULL)
		{
			ft_lsparsname(av[i], &folder, *ops);
			closedir(directory);
		}
		else
			ft_lsparsname(av[i], bt, *ops);
		i++;
	}
	ft_parsjoin(bt, &folder, j, *ops);
}
