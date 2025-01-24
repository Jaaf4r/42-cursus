/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:24:52 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/24 22:30:23 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_node *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_node	*curr;

	min = stack->value;
	pos = 0;
	min_pos = 0;
	curr = stack;
	while (curr)
	{
		if (curr->value < min)
		{
			min = curr->value;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

static void	push_smallest_two_to_b(t_node **stack_a, t_node **stack_b
, int *min_pos, int stack_size)
{
	if (*min_pos <= stack_size / 2)
	{
		while ((*min_pos)-- > 0)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while ((*min_pos)++ < stack_size)
		{
			rra(stack_a);
			write(1, "rra\n", 4);
		}
	}
	pb(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	pushes;
	int	min_pos;
	int	stack_size;

	size = ft_lstsize(*stack_a);
	pushes = size - 3;
	while (pushes > 0)
	{
		min_pos = find_min_position(*stack_a);
		stack_size = ft_lstsize(*stack_a);
		push_smallest_two_to_b(stack_a, stack_b, &min_pos, stack_size);
		pushes--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}
