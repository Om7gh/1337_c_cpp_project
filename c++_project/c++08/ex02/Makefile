# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 21:30:57 by omghazi           #+#    #+#              #
#    Updated: 2024/12/10 12:39:26 by omghazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
NAME = stack
CPPFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp MutanStack.tpp MutanStack.hpp
	c++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all