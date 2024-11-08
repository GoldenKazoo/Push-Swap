/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:44:01 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/28 18:06:46 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*previous;
	struct s_stack	*next;
	struct s_stack	*target;
	bool			above_med;


}	t_stack;

void	ft_swap(char *name, t_stack **stack);
void	ft_push(char *name, t_stack **stack_1, t_stack **stack_2);
void	ft_rotate_rev(char *name, t_stack **stack);
void	ft_rotate(char *name, t_stack **stack);
void	ft_double(char *name, t_stack **stack_a, t_stack **stack_b);
int		ft_strcmp(char *word_1, char *word_2);
int		ft_is_num(char c);
int		ft_atoi(char *string);
void	ft_print_stack(t_stack *stack);
t_stack	*ft_new_number(int number);
int		ft_number_in_stack(int number, t_stack *stack);
void	ft_add_back(int number, t_stack *stack);
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b);
int    ft_is_sorted(t_stack *stack_a);
void    ft_sort(t_stack **stack_a);
int	ft_stack_len(t_stack *stack);
t_stack *ft_biggest_node(t_stack *stack);
#endif
