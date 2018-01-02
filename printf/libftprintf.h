/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:27:53 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/16 10:32:17 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <time.h>

# define BUFF_SIZE 64
# define SIZE_H		(1)
# define SIZE_L		(2)
# define SIZE_J		(3)
# define SIZE_Z		(4)
# define SIZE_HH	(5)
# define SIZE_LL	(6)

typedef struct		s_op
{
	int		fd;
	int		nbpr;
	int		m;
	int		p;
	int		zero;
	int		space;
	int		htag;
	int		min;
	int		size;
	int		pre;
	int		mpre;
	char	conv;
	int		nboptions;
	int		neg;
	int		end;
}					t_op;
int					ft_printf(const char *str, ...);
void				ft_printcha(t_op *ops, va_list *ap);
void				ft_printstr(t_op *ops, va_list *ap);
void				ft_printptr(t_op *ops, va_list *ap);
void				ft_printint(t_op *ops, va_list *ap);
void				ft_printuint(t_op *ops, va_list *ap, int base);
void				ft_printoud(t_op *ops, va_list *ap);
size_t				ft_options(t_op *ops, const char *str, va_list *ap);
int					ft_conv(t_op *ops, char c, va_list *ap);
void				ft_printprintf(const char *str, t_op *ops, int len);
void				ft_printprintfw(int str, t_op *ops);
void				ft_printwstr(t_op *ops, va_list *ap);
void				ft_printopsm(char *str, t_op *ops, long long x);
void				ft_printopsnotm(char *str, t_op *ops, long long x);
void				ft_printmin(t_op *ops, size_t i, size_t j);
void				ft_printops(t_op *ops, long long int i);
void				ft_printdate(t_op *ops, va_list *ap);
int					ft_dprintf(int fd, const char *str, ...);
#endif
