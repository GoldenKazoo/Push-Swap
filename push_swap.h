#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int             number;
    struct  s_stack *next;
} t_stack;

void    ft_swap(char *name, t_stack **stack);