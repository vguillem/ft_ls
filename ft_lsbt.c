/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsbt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:53:37 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:24:43 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btp		*ft_newbtp(char *name, int ops)
{
	t_btp	*new;

	if (!(new = (t_btp *)ft_memalloc(sizeof(t_btp))))
		return (NULL);
	if (!(new->bt = ft_newbt(name, new, ops)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->su = 0;
	new->sg = 0;
	new->sl = 0;
	new->sp = 0;
	new->totalblock = 0;
	new->next = NULL;
	return (new);
}

static void	ft_lsinitbt(t_bt *bt)
{
	struct passwd	*uid;
	struct group	*gid;

	bt->l = NULL;
	bt->r = NULL;
	bt->user[0] = 0;
	bt->grp[0] = 0;
	if ((uid = getpwuid(bt->st.st_uid)))
		ft_strcpy(bt->user, uid->pw_name);
	if ((gid = getgrgid(bt->st.st_gid)))
		ft_strcpy(bt->grp, gid->gr_name);
}

static void	ft_lsinitstat(t_bt *bt, struct stat sta, char *buf, int ops)
{
	int		linklen;

	bt->link[0] = 0;
	if (ops & OPS_U)
		bt->date = sta.st_atime;
	else
		bt->date = sta.st_mtime;
	bt->st = sta;
	bt->size = sta.st_size;
	bt->nlink = sta.st_nlink;
	bt->dir = S_ISDIR(sta.st_mode);
	if (S_ISLNK(sta.st_mode))
	{
		linklen = readlink(buf, bt->link, PATH_MAX - 1);
		if (linklen == -1)
			ft_dprintf(2, "ft_ls: %s: %s\n", buf, strerror(errno));
		else
			bt->link[linklen] = 0;
	}
}

static void	ft_lsacl(t_bt *bt, char *buf)
{
	int		xattr;
	acl_t	acl;

	xattr = (int)listxattr(buf, NULL, 1, XATTR_NOFOLLOW);
	if (xattr > 0)
		bt->acl = '@';
	else
	{
		acl = acl_get_file(buf, ACL_TYPE_EXTENDED);
		if (acl)
		{
			acl_free((void *)acl);
			bt->acl = '+';
		}
		else
			bt->acl = ' ';
	}
}

t_bt		*ft_newbt(char *name, t_btp *ref, int ops)
{
	t_bt		*new;
	struct stat	sta;
	char		buf[PATH_MAX];

	if (!name)
		return (NULL);
	ref->bt ? ft_lspath(buf, ref->bt->data, name) : ft_strcpy(buf, name);
	if (lstat(buf, &sta) == -1)
	{
		if (errno == ENOENT)
			ft_dprintf(2, "ft_ls: %s: %s\n", name, strerror(errno));
		return (NULL);
	}
	if (!(new = (t_bt *)ft_memalloc(sizeof(t_bt))))
		return (NULL);
	ft_lsacl(new, buf);
	ft_lsinitstat(new, sta, buf, ops);
	ft_lsinitbt(new);
	ft_strcpy(new->data, name);
	ft_lssize(ref, new);
	ref->totalblock += sta.st_blocks;
	if (S_ISBLK(sta.st_mode) || S_ISCHR(sta.st_mode))
		ref->sp = 8;
	return (new);
}
