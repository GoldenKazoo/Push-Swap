/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:01:04 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/28 17:56:16 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_stack *stack)
{
	int		i;
	t_stack	*traveler;

	traveler = stack;
	i = 0;
	if (traveler == NULL)
		return (0);
	while (traveler -> next != NULL)
	{
		i++;
		traveler = traveler -> next;
	}
	i++;
	return (i);
}

int	ft_strcmp(char *word_1, char *word_2)
{
	int	i;

	i = 0;
	while (word_1[i] != '\0' || word_2[i] != '\0')
	{
		if (word_1[i] != word_2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_num(char c)
{
	if (c < '0' || c > '9')
		return (1);
	return (0);
}

int	ft_atoi(char *string)
{
	int		i;
	long	number;
	int		mult;

	i = 0;
	mult = 1;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			mult = -1;
		i++;
	}
	number = (string[i] - 48) * mult;
	i++;
	while (string[i] != '\0')
	{
		number = (number * 10) + (string[i] - 48);
		if ((number < -2147483648) || (number > 2147483647 && mult == 1))
		{
			printf("Number range is overflowing !");
			exit(1);
		}
		i++;
	}
	return (number);
}
t_stack *ft_biggest_node(t_stack *stack)
{	
	long			max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = -2147483649;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
