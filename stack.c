/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:38:39 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/28 17:49:31 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*traveler;

	traveler = stack;
	if (traveler == NULL)
		return ;
	while (traveler -> next != NULL)
	{
		printf("--------------------------------\n");
		printf("Number : %i\n", traveler -> number);
		printf("Next : %i\n", (traveler->next)-> number);
		traveler = traveler -> next;
	}
	printf("--------------------------------\n");
	printf("Number : %i\n", traveler -> number);
}

t_stack	*ft_new_number(int number)
{
	t_stack	*new_number;

	new_number = malloc(sizeof(t_stack));
	new_number -> number = number;
	new_number -> next = NULL;
	return (new_number);
}

int	ft_number_in_stack(int number, t_stack *stack)
{
	t_stack	*traveler;

	traveler = stack;
	while (traveler -> next != NULL)
	{
		if (traveler -> number == number)
			return (1);
		traveler = traveler -> next;
	}
	return (0);
}

void	ft_add_back(int number, t_stack *stack)
{
	t_stack	*traveler;

	traveler = stack;
	while (traveler -> next != NULL)
	{
		traveler = traveler -> next;
	}
	traveler -> next = ft_new_number(number);
}
