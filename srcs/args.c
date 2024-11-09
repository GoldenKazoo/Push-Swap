/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:40:25 by zchagar           #+#    #+#             */
/*   Updated: 2024/11/09 12:47:06 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_valid(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '+' || string[i] == '-')
		i++;
	while (string[i] != '\0')
	{
		if (ft_is_num(string[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_init_stack(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	int		current;

	i = 1;
	while (i < argc)
	{
		if (ft_arg_valid(argv[i]) == 1)
		{
			printf("Invalid arguments");
			exit (1);
		}
		current = ft_atoi(argv[i]);
		if (ft_number_in_stack(current, stack_a) == 0 && i == 1)
		{
			stack_a -> number = current;
			stack_a -> next = NULL;
		}
		if (ft_number_in_stack(current, stack_a) == 0 && i != 1)
			ft_add_back(current, stack_a);
		if (ft_number_in_stack(current, stack_a) == 1)
		{
			printf("You entered duplicates : %i", current);
			exit(1);
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		printf("Can't init stacks");
		return (1);
	}
	if (argc < 2)
	{
		printf("You have to enter at least 2 numbers");
		return (1);
	}
	ft_init_stack(stack_a, argc, argv);
	stack_b = NULL;

	ft_push("pa", &stack_a, &stack_b);
	ft_push("pa", &stack_a, &stack_b);
	ft_set_closest_small(stack_a, stack_b);
	printf("STACK_A :\n");
	ft_print_stack(stack_a);
	// printf("STACK_B :\n");
	// printf("--------------\n");
	// ft_sort(&stack_a);
	// ft_print_stack(stack_a);
}
