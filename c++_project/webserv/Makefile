SRC		=	srcs/main.cpp \
			srcs/Request/Connection.cpp \
			srcs/Request/Headers.cpp \
			srcs/Request/Request.cpp \
			srcs/Response/Cgi.cpp \
			srcs/Response/ErrorResponse.cpp \
			srcs/Response/FileExplorer.cpp \
			srcs/Response/Get.cpp \
			srcs/Response/Post.cpp \
			srcs/Response/Response.cpp \
			srcs/ServerManager/Core.cpp \
			srcs/ServerManager/Location.cpp \
			srcs/ServerManager/Server.cpp \
			srcs/ServerManager/ServerManager.cpp \
			srcs/utilities/BasicString.cpp \
			srcs/utilities/WSU.cpp
OBJ		=	$(SRC:.cpp=.o)
NAME	=	webserv
ERASE	= \033[2K\r
BLUE	= \033[34m
YELLOW	= \033[33m
GREEN	= \033[32m
END		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)
	@echo "\033[1;34m                                                                 \033[0m"
	@echo "\033[1;34m ██╗    ██╗███████╗██████╗ ███████╗███████╗██████╗ ██╗   ██╗\033[0m"
	@echo "\033[1;34m ██║    ██║██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██║   ██║\033[0m"
	@echo "\033[1;34m ██║ █╗ ██║█████╗  ██████╔╝███████╗█████╗  ██████╔╝██║   ██║\033[0m"
	@echo "\033[1;34m ██║███╗██║██╔══╝  ██╔══██╗╚════██║██╔══╝  ██╔══██╗██║   ██║\033[0m"
	@echo "\033[1;34m ╚███╔███╔╝███████╗██████╔╝███████║███████╗██║  ██║╚██████╔╝\033[0m"
	@echo "\033[1;34m  ╚══╝╚══╝ ╚══════╝╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝ ╚═════╝ \033[0m"
	@echo "\033[1;34m                                                                 \033[0m"
	@echo "\033[1;36m                     🚀 \033[1;34mwebserv\033[1;36m is ready! 🚀\033[0m"
	@echo "\033[1;34m                                                                 \033[0m"
	@c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)
	@printf "$(ERASE)$(GREEN)$@ created\n$(END)"
	@printf "$(ERASE)$(BLUE)run ./webserv\n$(END)"

%.o: %.cpp  srcs/Request/Connection.hpp \
			srcs/Request/Headers.hpp \
			srcs/Request/Request.hpp \
			srcs/Response/Cgi.hpp \
			srcs/Response/ErrorResponse.hpp \
			srcs/Response/FileExplorer.hpp \
			srcs/Response/Get.hpp \
			srcs/Response/Post.hpp \
			srcs/Response/Response.hpp \
			srcs/ServerManager/Core.hpp \
			srcs/ServerManager/Location.hpp \
			srcs/ServerManager/Server.hpp \
			srcs/ServerManager/ServerManager.hpp \
			srcs/utilities/BasicString.hpp \
			srcs/utilities/WSU.hpp \
			srcs/webserv.hpp
	@c++ -Wall -Wextra -Werror -std=c++98 -c  $< -o $@
	@printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

clean:
	@rm -f $(OBJ)
	@printf "$(YELLOW)object file removed$(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(YELLOW)$(NAME) program name removed$(END)\n"

re: fclean all

.PHONY: clean
