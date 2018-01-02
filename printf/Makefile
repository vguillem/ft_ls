# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:55:19 by vguillem          #+#    #+#              #
#    Updated: 2017/12/30 14:39:42 by vguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TMPNAME = tmplibftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS =				\
			ft_printf.c \
			ft_printcha.c \
			ft_printint.c \
			ft_printops.c \
			parse.c \
			ft_printhtag.c \
			ft_printstr.c \
			ft_printwstr.c \
			ft_printptr.c \
			ft_printwcha.c \
			ft_printdate.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(TMPNAME) $(OBJS)
	make -C ../libft/
	libtool -static -o $(NAME) $(TMPNAME) ../libft/libft.a
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $? -c -o $@

clean:
	make -C ../libft/ clean
	/bin/rm -f $(OBJS)
	/bin/rm -f $(TMPNAME)
	/bin/rm -f $(NAME)

fclean: clean
	make -C ../libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
