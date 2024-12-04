
NAME				= push_swap


INC					= includes/
SRC_DIR				= srcs/
OBJ_DIR				= obj/


CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f


COMMANDS_DIR		=	$(SRC_DIR)op/push.c \
						$(SRC_DIR)op/rev_rotate.c \
						$(SRC_DIR)op/rotate.c \
						$(SRC_DIR)op/sort_stacks.c \
						$(SRC_DIR)op/sort_three.c \
						$(SRC_DIR)op/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push/handle_errors.c \
						$(SRC_DIR)push/init_a_to_b.c \
						$(SRC_DIR)push/init_b_to_a.c \
						$(SRC_DIR)push/push_swap.c \
						$(SRC_DIR)push/split.c \
						$(SRC_DIR)push/stack_init.c \
						$(SRC_DIR)push/stack_utils.c \
						$(SRC_DIR)push/ft_isdigit.c


SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)


OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


start:				
					@make all


all: 				$(NAME)

$(NAME): 			$(OBJ)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)


$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)

fclean: 			clean
					@$(RM) $(NAME)

re: 				fclean all


.PHONY: 			start all clean fclean re