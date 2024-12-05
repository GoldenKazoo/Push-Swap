CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/putstr.c srcs/sort.c srcs/push_swap.c srcs/init_phase_1.c srcs/init_phase_2.c srcs/errors.c \
		srcs/stack_init.c srcs/stack_utils.c srcs/sort_utils.c \
		srcs/push.c srcs/rotate.c srcs/rev_rotate.c  srcs/swap.c srcs/split.c \

OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -g $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

