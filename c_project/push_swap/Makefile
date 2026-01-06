SRC=$(addprefix Mandatory/, libft/ft_atoi.c\
							libft/ft_lstnew.c\
							libft/ft_lstadd_back.c\
							libft/ft_lstadd_front.c\
							libft/ft_lstsize.c\
							libft/ft_lstclean.c\
							libft/ft_split.c\
							utils/utils1.c\
							utils/utils2.c\
							parse/parse.c\
							actions/push.c\
							actions/swap.c\
							actions/rotate.c\
							actions/reverse_rotate.c\
							algo/algo_utils.c\
							algo/algo_utils2.c\
							algo/easy_sort.c\
							algo/heavy_sort.c\
							main.c\
							)
SRC_BONUS=$(addprefix Bonus/,utils/utils1_bonus.c\
							 utils/utils2_bonus.c\
							 utils/utils3_bonus.c\
							 utils/get_next_line.c\
							 utils/get_next_line_utils.c\
							 actions/push_bonus.c\
							 actions/swap_bonus.c\
							 actions/rotate_bonus.c\
							 actions/reverse_rotate_bonus.c\
							 parse_bonus/parse_bonus.c\
							 libft_bonus/ft_atoi.c\
							 libft_bonus/ft_lstnew.c\
							 libft_bonus/ft_lstadd_back.c\
							 libft_bonus/ft_lstadd_front.c\
							 libft_bonus/ft_lstsize.c\
							 libft_bonus/ft_lstclean.c\
							 libft_bonus/ft_split.c\
							 libft_bonus/ft_strncmp.c\
							 checker.c\
							)
OBJ=$(SRC:.c=.o)
BOBJ=$(SRC_BONUS:.c=.o)
NAME=push_swap
NAME_BONUS=checker
HEADER=include/push_swap.h
HEADER_BONUS=include/push_swap_bonus.h include/get_next_line.h
CC=cc
CFLAG=-Wall -Wextra -Werror -g
Mandatory/%.o:Mandatory/%.c $(HEADER)
		$(CC) $(CFLAG) -c $< -o $@
Bonus/%.o:Bonus/%.c $(HEADER_BONUS)
		$(CC) $(CFLAG) -c $< -o $@
all:$(NAME)
$(NAME):$(OBJ)
		$(CC) $(CFLAG) $(OBJ) -o $(NAME)
bonus:$(NAME_BONUS)
$(NAME_BONUS):$(BOBJ)
		$(CC) $(CFLAG) $(BOBJ) -o $(NAME_BONUS)
clean:
		rm -f $(OBJ) $(BOBJ)
fclean:clean
		rm -f $(NAME) $(NAME_BONUS)
re:fclean all
.PHONY:clean