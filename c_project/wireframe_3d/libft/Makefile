# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 00:47:15 by omghazi           #+#    #+#              #
#    Updated: 2024/02/12 18:52:24 by omghazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_bzero.c		\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_split.c		\
		ft_putendl_fd.c		\
		get_next_line.c		\
		get_next_line_utils.c \
		ft_substr.c	\
		ft_strdup.c \
		ft_strchr.c \
		ft_strrchr.c


NAME = libft.a
CC = cc
CFLAGS = -Wextra -Werror -Wall
RM = rm -f
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar cr $(NAME) $(OBJS)

%.o: %.c libft.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean
