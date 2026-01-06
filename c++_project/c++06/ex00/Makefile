# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 11:53:30 by omghazi           #+#    #+#              #
#    Updated: 2024/12/05 12:02:13 by omghazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ScalarConverter.cpp	main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = converter
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp ScalarConverter.hpp
	c++ $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :	fclean all
