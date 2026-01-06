# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 18:35:18 by omghazi           #+#    #+#              #
#    Updated: 2024/10/15 17:26:40 by omghazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = human

SRC = HumanA.cpp	HumanB.cpp	Weapon.cpp	main.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	printf '\033[1m\033[37m[ ✔ ] %s\n\033[0m' "Create human"

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.SILENT: