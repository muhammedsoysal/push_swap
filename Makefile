NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

SRCS = push_swap.c\
       sort/basic_sort.c\
	   sort/radix_sort.c\
	   utils/utils_lib.c\
	   utils/utils_sort.c\
	   utils/utils_error1.c\
	   utils/utils_error2.c\
	   actions/swap.c\
	   actions/push.c\
	   actions/rotate.c\
	   actions/reverse_rotate.c\
	   

LIBFT = lib/Libft/libft.a
FT_PRINTF = lib/printf/libftprintf.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(FT_PRINTF)
	@echo "$(YELLOW)Compiling and Linking...$(RESET)"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)Push_swap Executable Created!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make all -s -C lib/Libft

$(FT_PRINTF):
	@echo "$(YELLOW)Building printf...$(RESET)"
	@make all -s -C lib/printf

clean:
	@make clean -s -C lib/Libft
	@make clean -s -C lib/printf

fclean: clean
	@rm -f $(LIBFT) $(FT_PRINTF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
