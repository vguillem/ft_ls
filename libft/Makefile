# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:55:19 by vguillem          #+#    #+#              #
#    Updated: 2017/12/30 14:39:27 by vguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS =				\
		ft_putchar.c \
		ft_putstr.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_strdup.c \
		ft_memcmp.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c\
		ft_isascii.c \
		ft_isprint.c \
		ft_islower.c \
		ft_isupper.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_iswhitespace.c \
		ft_countwords.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_swap.c \
		ft_printwordstables.c \
		ft_foreach.c \
		ft_ultoabase.c \
		ft_ltoabase.c \
		ft_wputchar_fd.c \
		ft_tolowers.c \
		ft_touppers.c \
		ft_putunbr.c \
		ft_realloc.c \
		ft_memconcat.c \
		ft_nbrlen.c \
		ft_putnchar.c \
		ft_charlen.c \
		ft_wstrlen.c \
		ft_topos.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $? -c -o $@

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
