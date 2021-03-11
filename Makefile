NAME_PS = push_swap
NAME_C = checker

MLX = ./mlx/libmlx.a

LIBFT = ./libft/libft.a

SRC_S =	shared/check_args.c \
		shared/count_args.c \
		shared/exit.c \
		shared/ft_atoi_ps.c \
		shared/ft_atol.c \
		shared/ft_calloc_ps.c \
		shared/ft_isdigit.c \
		shared/ft_isin.c \
		shared/ft_putchar_fd.c \
		shared/ft_putnbr_fd.c \
		shared/ft_putstr_fd.c \
		shared/ft_split.c \
		shared/ft_strchr.c \
		shared/ft_strcmp.c \
		shared/ft_strcpy.c \
		shared/ft_strdel.c \
		shared/ft_strlen.c \
		shared/ft_strdup_ps.c \
		shared/ft_substr.c \
		shared/get_next_line.c \
		shared/get_stack.c \
		shared/init_struct.c \
		shared/malloc_and_fill.c \
		shared/print_stack.c \
		shared/sort_array.c

SRC_P = srcs_push_swap/case_big2.c \
		srcs_push_swap/case_big.c \
		srcs_push_swap/case_six.c \
		srcs_push_swap/case_three.c \
		srcs_push_swap/find_median.c \
		srcs_push_swap/minmax.c \
		srcs_push_swap/pab.c \
		srcs_push_swap/push_swap.c \
		srcs_push_swap/rab.c \
		srcs_push_swap/rrab.c \
		srcs_push_swap/sab.c \
		srcs_push_swap/sort_part.c

SRC_C = srcs_checker/action.c \
		srcs_checker/args_and_flags.c \
		srcs_checker/check.c \
		srcs_checker/check_if_sorted.c \
		srcs_checker/checker.c \
		srcs_checker/pab_action.c \
		srcs_checker/print_nb_actions.c \
		srcs_checker/rab_action.c \
		srcs_checker/rrab_action.c \
		srcs_checker/sab_action.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_P = $(SRC_P:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

FT_FLAGS = -Wall -Wextra -Werror

all:
	@make -C ./shared/ft_printf
	@gcc -o $(NAME_PS) $(FT_FLAGS) $(SRC_S) $(SRC_P) ./shared/ft_printf/libftprintf.a
	@gcc -o $(NAME_C) $(FT_FLAGS) $(SRC_S) $(SRC_C) ./shared/ft_printf/libftprintf.a
	@echo "Compilation checker\t\t\033[0;32m[OK]\033[0m"
	@echo "Compilation push_swap\t\t\033[0;32m[OK]\033[0m"


clean:
	@make -C ./shared/ft_printf clean
	@rm -rf $(OBJ_S)
	@rm -rf $(OBJ_C)
	@rm -rf $(OBJ_P)
	@echo "Cleaning Objects\t\t\033[0;32m[OK]\033[0m"

fclean:
	@rm -rf $(OBJ_S)
	@rm -rf $(OBJ_C)
	@rm -rf $(OBJ_P)
	@echo "Cleaning Objects\t\t\033[0;32m[OK]\033[0m"
	@make -C ./shared/ft_printf fclean
	@rm -rf ${NAME_PS}
	@rm -rf ${NAME_C}
	@echo "Cleaning exec\t\t\t\033[0;32m[OK]\033[0m"

re: fclean all

phony: all clean fclean re
