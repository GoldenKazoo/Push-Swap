CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRCS = srcs/args.c srcs/free.c srcs/instructions.c srcs/stack.c srcs/utils.c srcs/sort.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
