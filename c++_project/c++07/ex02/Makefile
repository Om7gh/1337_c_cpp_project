# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 10:10:46 by omghazi           #+#    #+#              #
#    Updated: 2024/12/08 13:41:27 by omghazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = array
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Array.hpp Array.tpp
	c++ $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :	fclean all