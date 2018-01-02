/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsacces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:35:36 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:18:53 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	ft_lssuid(t_bt *bt)
{
	if (S_IXUSR & bt->st.st_mode)
	{
		if (S_ISUID & bt->st.st_mode)
			return ('s');
		else
			return ('x');
	}
	else if (S_ISUID & bt->st.st_mode)
		return ('S');
	return ('-');
}

static char	ft_lssticky(t_bt *bt)
{
	if (S_IXOTH & bt->st.st_mode)
	{
		if (S_ISVTX & bt->st.st_mode)
			return ('t');
		else
			return ('x');
	}
	else if (S_ISVTX & bt->st.st_mode)
		return ('T');
	return ('-');
}

static char	ft_lssgid(t_bt *bt)
{
	if (S_IXGRP & bt->st.st_mode)
	{
		if (S_ISGID & bt->st.st_mode)
			return ('s');
		else
			return ('x');
	}
	else if (S_ISGID & bt->st.st_mode)
		return ('S');
	return ('-');
}

static void	ft_lsaccesright(t_bt *bt, char *buf)
{
	if (S_IRUSR & bt->st.st_mode)
		buf[1] = 'r';
	if (S_IWUSR & bt->st.st_mode)
		buf[2] = 'w';
	buf[3] = ft_lssuid(bt);
	if (S_IRGRP & bt->st.st_mode)
		buf[4] = 'r';
	if (S_IWGRP & bt->st.st_mode)
		buf[5] = 'w';
	buf[6] = ft_lssgid(bt);
	if (S_IROTH & bt->st.st_mode)
		buf[7] = 'r';
	if (S_IWOTH & bt->st.st_mode)
		buf[8] = 'w';
	buf[9] = ft_lssticky(bt);
}

void		ft_lsacces(t_bt *bt)
{
	char	acces[12];

	ft_memset(acces, '-', 12);
	acces[10] = bt->acl;
	acces[11] = 0;
	if (S_ISDIR(bt->st.st_mode))
		acces[0] = 'd';
	else if (S_ISCHR(bt->st.st_mode))
		acces[0] = 'c';
	else if (S_ISBLK(bt->st.st_mode))
		acces[0] = 'b';
	else if (S_ISFIFO(bt->st.st_mode))
		acces[0] = 'p';
	else if (S_ISLNK(bt->st.st_mode))
		acces[0] = 'l';
	else if (S_ISSOCK(bt->st.st_mode))
		acces[0] = 's';
	ft_lsaccesright(bt, acces);
	ft_printf("%s", acces);
}
