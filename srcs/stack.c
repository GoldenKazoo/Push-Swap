/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:38:39 by zchagar           #+#    #+#             */
/*   Updated: 2024/11/09 11:52:20 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
