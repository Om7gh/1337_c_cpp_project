# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 20:27:31 by omghazi           #+#    #+#              #
#    Updated: 2024/12/05 20:28:20 by omghazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = A.cpp    B.cpp    Base.cpp C.cpp    main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = converter
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp A.hpp    B.hpp    Base.hpp C.hpp
	c++ $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :	fclean all
