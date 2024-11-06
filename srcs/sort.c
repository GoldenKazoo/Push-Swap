#include "push_swap.h"

int    ft_is_sorted(t_stack *stack_a)
{
    t_stack *traveler;
    
    traveler = stack_a;
    while (traveler -> next != NULL)
    {
        if (traveler -> number > (traveler -> next) -> number)
        {    
            printf("Is not sorted");
            return (1);
        }
        traveler = traveler -> next;
    }
    printf("Is sorted");
    return (0);
}

void    ft_sort(t_stack **stack_a, t_stack **stack_b)
{
}
