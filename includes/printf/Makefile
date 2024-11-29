# Standard
NAME				= push_swap

# Directories
INC					= includes/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
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

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re