# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 16:03:39 by omghazi           #+#    #+#              #
#    Updated: 2024/02/18 08:28:26 by omghazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		./Mandatory/main.c \
	  		./Mandatory/init.c	\
	  		./Mandatory/projection.c \
	  		./Mandatory/read_map.c	\
	  		./Mandatory/utils2.c	\
	  		./Mandatory/utils.c	\
	  		./Mandatory/draw.c		\
			./Mandatory/event.c

BONUS_SRC = Bonus/main_bonus.c \
			Bonus/init_bonus.c \
			Bonus/projection_bonus.c \
			Bonus/read_map_bonus.c \
			Bonus/utils2_bonus.c \
			Bonus/utils_bonus.c \
			Bonus/draw_bonus.c \
			Bonus/hook_mouse_bonus.c \
			Bonus/hook_key_bonus.c	\
			Bonus/rotate_map.c	\
			Bonus/free_exit.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BONUS_SRC:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = fdf

NAME_BON = fdf_bonus

HEADER = ./Mandatory/fdf.h ./libft/libft.h

HEADER_BONUS = ./Bonus/fdf_bonus.h ./Bonus/hook_bonus.h ./libft/libft.h

LIBFT = libft/libft.a

all : $(NAME)

bonus : $(NAME_BON)

Mandatory/%.o: Mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	$(MAKE) -C ./libft/
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(NAME_BON) : $(BOBJ)
	$(MAKE) -C ./libft/
	$(CC) -lmlx -framework OpenGL -framework AppKit $(BOBJ) -o $(NAME_BON) $(LIBFT)

Bonus/%.o: Bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
		rm -f $(OBJ) $(BOBJ)
		cd ./libft && make clean
fclean : clean
		rm -f $(NAME) $(NAME_BON)
		cd ./libft && make fclean

re : fclean all

.PHONY: clean