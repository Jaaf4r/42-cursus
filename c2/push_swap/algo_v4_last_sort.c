/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v4_last_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:20:08 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 19:20:09 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_per_cost(t_node **stack_a, int stack_a_size, int smallest_pos)
{
	int	cost;

	cost = calculate_rot_cost(stack_a_size, smallest_pos);
	while (cost > 0)
	{
		ra(stack_a);
		cost--;
		write(1, "ra\n", 3);
	}
	while (cost < 0)
	{
		rra(stack_a);
		cost++;
		write(1, "rra\n", 4);
	}
}

void	rotate_stack_a(t_node **stack_a)
{
	t_node	*curr;
	int		smallest_pos;
	int		smallest_value;
	int		index;
	int		stack_a_size;

	curr = *stack_a;
	smallest_pos = 0;
	index = 0;
	smallest_value = curr->value;
	stack_a_size = ft_lstsize(*stack_a);
	while (curr)
	{
		if (curr->value < smallest_value)
		{
			smallest_value = curr->value;
			smallest_pos = index;
		}
		curr = curr->next;
		index++;
	}
	rot_per_cost(stack_a, stack_a_size, smallest_pos);
}
