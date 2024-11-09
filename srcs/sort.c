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
void	ft_sort_three(t_stack **stack)
{
		t_stack *biggest;
		biggest = ft_biggest_node(*stack);
		if (biggest == *stack)
			ft_rotate("ra", stack);
		if ((*stack) -> next == biggest)
			ft_rotate_rev("rra", stack);
		if ((*stack) -> number > ((*stack) -> next) -> number)
			ft_swap("sa", stack);
}
void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{

	if (ft_stack_len(*stack_a) == 2 && ft_is_sorted(*stack_a) == 1)
	{
		ft_swap("sa", &(*stack_a));
	}
	else if (ft_stack_len(*stack_a) == 3 && ft_is_sorted(*stack_a) == 1)
	{
		ft_sort_three(stack_a);
	}
	else
	{
		ft_sort_alg(stack_a, stack_b);
	}
	sleep(1);
}
