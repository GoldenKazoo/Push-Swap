/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:01:19 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/28 18:03:31 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char *name, t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	if (!(*stack))
		return ;
	second = ((*stack)-> next);
	if (!((*stack) == NULL || (*stack)-> next == NULL))
	{
		first -> next = second -> next;
		second -> next = first;
		*stack = second;
	}
	if (ft_strcmp(name, "sa") == 0)
		printf("sa\n");
	if (ft_strcmp(name, "sb") == 0)
		printf("sb\n");
}

void	ft_double(char *name, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp("ss", name) == 0)
	{
		ft_swap("", stack_a);
		ft_swap("", stack_b);
		printf("ss\n");
	}
	if (ft_strcmp("rr", name) == 0)
	{
		ft_swap("", stack_a);
		ft_swap("", stack_b);
		printf("rr\n");
	}
	if (ft_strcmp("rrr", name) == 0)
	{
		ft_swap("", stack_a);
		ft_swap("", stack_b);
		printf("rrr\n");
	}
}

void	ft_push(char *name, t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*push;

	push = malloc(sizeof(t_stack));
	if (!((*stack_1) == NULL))
	{
		push -> number = (*stack_1)-> number;
		push -> next = *stack_2;
		*stack_1 = (*stack_1)-> next;
		*stack_2 = push;
	}
	if (ft_strcmp(name, "pa") == 0)
		printf("pa\n");
	if (ft_strcmp(name, "pb") == 0)
		printf("pb\n");
}

void	ft_rotate_rev(char *name, t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	last = *stack;
	second_last = NULL;
	if (!last || !(last->next))
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
	if (ft_strcmp(name, "rrb") == 0)
		printf("rrb\n");
	if (ft_strcmp(name, "rrb") == 0)
		printf("rrb\n");
}

void	ft_rotate(char *name, t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = *stack;
	if (!first || !(first->next))
		return ;
	while (last->next)
	{
		last = last->next;
	}
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	if (ft_strcmp(name, "ra") == 0)
		printf("ra\n");
	if (ft_strcmp(name, "rb") == 0)
		printf("rb\n");
}
