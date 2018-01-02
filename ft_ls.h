/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:53:28 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/31 09:01:46 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include "libft/libft.h"
# include "printf/libftprintf.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <limits.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>
# include <sys/acl.h>

# define OPS_RUP	(1)
# define OPS_R		(2)
# define OPS_L		(4)
# define OPS_T		(8)
# define OPS_A		(16)
# define OPS_F		(32)
# define OPS_U		(64)
# define OPS_D		(128)
# define OPS_G		(256)
# define OPS_M		(512)
# define OPS_N		(1024)
# define OPS_UN		(2048)
# define LEN_C		1024
# define MINI(x)	(x & 0xffffff)
# define MAXI(x)	((x >> 24) & 0xff)

typedef struct	s_bt
{
	struct s_bt		*r;
	struct s_bt		*l;
	char			data[PATH_MAX];
	struct stat		st;
	time_t			date;
	char			link[PATH_MAX];
	char			user[LEN_C];
	char			grp[LEN_C];
	int				nlink;
	int				size;
	int				dir;
	char			acl;
}				t_bt;

typedef struct	s_btp
{
	t_bt			*bt;
	unsigned		totalblock;
	int				su;
	int				sg;
	int				sp;
	int				sl;
	struct s_btp	*next;
}				t_btp;

t_btp			*ft_newbtp(char *name, int ops);
void			ft_lsparse(int ac, char **av, t_btp **btp, int *ops);
void			ft_ls(char *name, int *ops, t_btp *bt);
void			ft_lsprint(t_btp *bt, int ops);
t_bt			*ft_newbt(char *name, t_btp *ref, int ops);
void			ft_lsprintbadop(char c);
void			ft_lsprinthelp(void);
void			ft_sortbtascii(t_bt *toplace, t_bt *ref);
void			ft_sortbtasciir(t_bt *toplace, t_bt *ref);
void			ft_lsreadnbt(t_bt *bt, t_btp *origin, int *ops);
void			ft_lsprintbt(t_bt *bt, int ops, t_btp *ref);
void			ft_lsreadprint(t_bt *bt, int ops, t_btp *ref);
void			ft_parseascii(t_btp *btnew, t_btp **ref);
void			ft_parseasciir(t_btp *btnew, t_btp **ref);
void			ft_sortbtdate(t_bt *toplace, t_bt *ref);
void			ft_sortbtdater(t_bt *toplace, t_bt *ref);
void			ft_lspath(char *buf, char *origin, char *ref);
void			ft_lsacces(t_bt *bt);
void			ft_lsfr(t_bt *toplace, t_bt *ref, int ops);
void			ft_lsf(t_bt *toplace, t_bt *ref, int ops);
void			ft_lssize(t_btp *origin, t_bt *bt);
void			ft_parseu(t_btp *btnew, t_btp **ref);
void			ft_parseur(t_btp *btnew, t_btp **ref);
void			ft_sortsamedate(t_bt *toplace, t_bt *ref);
void			ft_sortsamedater(t_bt *toplace, t_bt *ref);
#endif
