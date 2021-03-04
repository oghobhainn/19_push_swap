PUSH_SWAP =		push_swap
CHECKER =		checker
NAME = $(PUSH_SWAP) $(CHECKER)

COMP =			gcc -Wall -Wextra -Werror -I includes
OBJ_DIR =		obj/
S_SRC_DIR =		shared/
P_SRC_DIR =		push_swap/
C_SRC_DIR =		checker/

S_SRC =			check_args.c \
				count_args.c \
				exit.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_isdigit.c \
				ft_isin.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_substr.c \
				get_next_line.c \
				get_stack.c \
				init_struct.c \
				malloc_and_fill.c \
				print_stack.c

P_SRC_DIR =		push_swap.c

C_SRC_DIR =		actions.c \
				check_if_sorted.c \
				checker.c \
				pab_action.c \
				rab_action.c \
				rrab_action.c \
				sab_action.c

S_OBJ =			$(S_SRC:%.c=%.o)
P_OBJ =			$(P_SRC:%.c=%.o)
C_OBJ =			$(C_SRC:%.c=%.o)
OBJ =			$(S_OBJ) $(P_OBJ) $(C_OBJ)

S_SRC_PATH =	$(S_SRC:%=$(S_SRC_DIR)%)
P_SRC_PATH =	$(P_SRC:%=$(P_SRC_DIR)%)
C_SRC_PATH =	$(C_SRC:%=$(C_SRC_DIR)%)
SRC_PATH = 		$(S_SRC_PATH) $(P_SRC_PATH) $(C_SRC_PATH)

S_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(S_OBJ))
P_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(P_OBJ))
C_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(C_OBJ))
OBJ_PATH =		$(S_OBJ_PATH) $(P_OBJ_PATH) $(C_OBJ_PATH)

all:			color 
				$(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m PUSH_SWAP AND CHECKER COMPLETE \033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(S_OBJ_PATH) $(P_OBJ_PATH) *.a -o push_swap \
				@gcc $(S_OBJ_PATH) $(C_OBJ_PATH) *.a -o checker
				
$(S_OBJ_PATH):	$(S_SRC_PATH)
				@$(MAKE) $(S_OBJ)

$(P_OBJ_PATH):	$(P_SRC_PATH)
				@$(MAKE) $(P_OBJ)

$(C_OBJ_PATH):	$(C_SRC_PATH)
				@$(MAKE) $(C_OBJ)

$(S_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(S_SRC_DIR)$(@:%.o=%.c)
$(C_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(C_SRC_DIR)$(@:%.o=%.c)
$(P_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(P_SRC_DIR)$(@:%.o=%.c)

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR)
				@echo "\\n\033[32;1m Cleaned libft object files \033[0m"

fclean:			clean
				@/bin/rm -f $(PUSH_SWAP) $(CHECKER)
				@echo "\\n\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: 			fclean all

.PHONY:			all clean flcean re color