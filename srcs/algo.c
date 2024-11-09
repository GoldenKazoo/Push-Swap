#include "push_swap.h"
#include <limits.h>

void ft_set_index(t_stack *a, t_stack *b) {
	int i = 0;

	while (a) {
		a->index = i;
		if (i <= ft_stack_len(a))
			a->above_med = 0;
		else
			a->above_med = 1;
		i++;
		a = a->next;
	}

	i = 0;
	while (b) {
		b->index = i;
		if (i <= ft_stack_len(b))
			b->above_med = 0;
		else
			b->above_med = 1;
		i++;
		b = b->next;
	}
}

void ft_set_cost(t_stack *a, t_stack *b)
{
	while (a)
	{
		a->cost = a->index;
		if (a->above_med == 1)
			a->cost = ft_stack_len(a) - a->index;
		if (a->target)
		{
			if (a->target->above_med == 0)
				a->cost += a->target->index;
			else
				a->cost += ft_stack_len(b) - a->target->index;
		}
		a = a->next;
	}
}
void	ft_cheapest(t_stack	*stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	while(stack)
	{
		if(stack -> cost < cheapest_value)
		{
			cheapest_value = stack -> cost;
			cheapest_node = stack;
		}
		stack = stack -> next;
	}
	cheapest_node -> cheap = 0;
}
void	ft_refresh_nodes_a(t_stack *a, t_stack *b)
{
	ft_set_index(a, b);
	ft_set_closest_small(a, b); 	//Etape 2 : on set la target la plus petite et la plus proche si y a pas le plus grand
	ft_set_cost(a, b);				//Etape 3 : on calcule le cout pour mettre le node quón regarde et sa target en haut des piles
	ft_cheapest(a);
}
void	ft_refresh_nodes_b(t_stack *a, t_stack *b)
{
	ft_set_index(a, b);
}
t_stack    *ft_point_to_number(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack -> number == n)
			return (stack);
		stack = stack -> next;
	}
	return (NULL);
}

void ft_set_closest_small(t_stack *a, t_stack *b) {
	int n;
	long max;
	int delta;
	t_stack *b_start = b;

	max = b->number;
	while (b)
	{
		if (max < b->number)
		{
			max = b->number;
		}
		b = b->next;
	}
	b = b_start;

	while (a) {
		delta = INT_MAX;
		b = b_start;
		while (b) {
			if ((a->number - b->number) < delta && (a->number - b->number) > 0) {
				delta = (a->number - b->number);
				n = b->number;
			}
			b = b->next;
		}
		if (delta == INT_MAX) {
			a->target = ft_point_to_number(b_start, max);
		} else {
			a->target = ft_point_to_number(b_start, n);
		}
		a = a->next;
	}
}


void ft_set_closest_big(t_stack *a, t_stack *b) {
	int n;
	long min;
	int delta;
	t_stack *b_start = b;

	min = b->number;
	while (b)
	{
		if (min > b->number) {
			min = b->number;
		}
		b = b->next;
	}
	b = b_start;

	while (a)
	{
		delta = INT_MAX;
		b = b_start;
		while (b)
		{
			if ((a->number - b->number) > delta && (a->number - b->number) < 0)
			{
				delta = (a->number - b->number);
				n = b->number;
			}
			b = b->next;
		}
		if (delta == INT_MAX) {
			a->target = ft_point_to_number(b_start, min);
		} else {
			a->target = ft_point_to_number(b_start, n);
		}
		a = a->next;
	}
}

void	pushing_to(t_stack **a, t_stack *top, char stack)
{
	while(*a != top)
	{
		if (stack == 'a')
		{
			if (top -> above_med)
				ft_rotate("ra", a);
			else
				ft_rotate_rev("rra", a);
		}
		else
		{
			if (top -> above_med)
				ft_rotate("rb", a);
			else
				ft_rotate_rev("rrb", a);
		}
	}
}
t_stack	*get_cheapest(t_stack *a)
{
	while(a)
	{
		if (a -> cheap == 0)
			return (a);
	}
	return (NULL);
}
void	ft_moove_1(t_stack **a, t_stack **b)
{
	t_stack	*cheap_node;

	cheap_node = get_cheapest(*a);
	if (cheap_node -> above_med && cheap_node -> target -> above_med)
	{
		ft_double("rr", a, b);
	}
	else if ((cheap_node -> above_med) == 1 && (cheap_node -> target -> above_med) == 1)
	{
		ft_double("rrr", a, b);
	}
	pushing_to(a, cheap_node, 'a');
	pushing_to(a, cheap_node -> target, 'b');
	ft_push("pb", b, a);
}
void	ft_sort_alg(t_stack **a, t_stack **b)
{
	//Etape 1 : on push 2 premiers elements dans B
	ft_push("pb", a, b);
	ft_push("pb", a, b);
	while (ft_stack_len(*a) != 3) 	// on repeat 2, 3 et 4 jusquá avoir stacklen(a == 3)
	{
		ft_refresh_nodes_a(*a, *b); //Etape 2 et 3
		ft_moove_1(a, b);			//Etape 4 : on effectue la suite dínstruction la moins couteuse
	}
	ft_sort_three(a);
	//Etape 5 : on set la target la plus grande et la plus proche si y a pas, la plus petit
	ft_set_closest_big(*a, *b);
	//Etape 7 : regarde la mediane si c'est en dessous, rra sinon ra puis on push l'elements
}
