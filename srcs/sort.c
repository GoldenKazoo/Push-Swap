#include "push_swap.h"

int    ft_is_sorted(t_stack *stack_a)
{
    t_stack *traveler;
    
    traveler = stack_a;
    while (traveler -> next != NULL)
    {
        if (traveler -> number > (traveler -> next) -> number)
        {    
            printf("Is not sorted\n");
            return (1);
        }
        traveler = traveler -> next;
    }
    printf("Is sorted\n");
    return (0);
}

void    ft_sort(t_stack **stack_a)
{
    t_stack *biggest;

    if (ft_stack_len(*stack_a) == 2 && ft_is_sorted(*stack_a) == 1)
    {
	    ft_swap("sa", &(*stack_a));
    }
    else if (ft_stack_len(*stack_a) == 3 && ft_is_sorted(*stack_a) == 1)
    {
        biggest = ft_biggest_node(*stack_a);
        if (biggest == *stack_a)
            ft_rotate("ra", stack_a);
        if ((*stack_a) -> next == biggest)
            ft_rotate_rev("rra", stack_a);
        if ((*stack_a) -> number > ((*stack_a) -> next) -> number)
            ft_swap("sa", stack_a);
    }
    else
    {
        
    }
    sleep(1);
}
