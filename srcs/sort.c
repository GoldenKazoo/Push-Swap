#include "../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}