# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:55:19 by vguillem          #+#    #+#              #
#    Updated: 2017/12/30 17:08:47 by vguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS =				main.c \
					ft_ls.c \
					ft_parse.c \
					ft_lsbt.c \
					ft_lsprint.c \
					ft_lsreadbt.c \
					ft_parseascii.c \
					ft_date.c \
					ft_dater.c \
					ft_lsacces.c \
					ft_lssize.c \
					ft_lssortu.c \


INCLUDE =	libft/libft.h \
			printf/libftprintf.h \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C printf/
	$(CC) $(FLAGS) $(OBJS) -L printf/ -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $? -c -o $@

clean:
	make -C printf/ clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C printf/ fclean
	/bin/rm -f $(NAME)

re: fclean all
