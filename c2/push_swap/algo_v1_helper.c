/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v1_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:24:57 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/24 22:24:58 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (stack && stack->next)
	{
		while (stack->next)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

int	is_reversed(t_node *stack_a)
{
	if (stack_a && stack_a->value)
	{
		while (stack_a->next)
		{
			if (stack_a->value < stack_a->next->value)
				return (0);
			stack_a = stack_a->next;
		}
	}
	return (1);
}

int	calculate_rot_cost(int stack_size, int index)
{
	if (index <= stack_size / 2)
		return (index);
	return (-(stack_size - index));
}

int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
