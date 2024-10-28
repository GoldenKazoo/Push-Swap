#include "push_swap.h"

void    ft_swap(char *name, t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    first = *stack;
    second = ((*stack) -> next);
    if ( !((*stack) == NULL || (*stack) -> next == NULL))
    {
        first -> next = second -> next;
        second -> next = first;
        *stack = second;
    }
    if (name == "sa")
        printf("sa");
    if (name == "sb")
        printf("sb");
}

void    ft_push(char *name, t_stack **stack, t_stack **stack_b)
{
    if (!((*stack) == NULL || (*stack) -> next == NULL))
    {
        first -> next = second -> next;
        second -> next = first;
        *stack = second;
    }
}