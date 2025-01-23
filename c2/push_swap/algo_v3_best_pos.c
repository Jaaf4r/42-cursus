/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v3_best_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:03:01 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 18:03:02 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_or_largest(t_node *curr, int *min_val, int *max_val)
{
	int	min_pos;
	int	pos;

	min_pos = 0;
	pos = 0;
	while (curr)
	{
		if (curr->value < *min_val)
		{
			*min_val = curr->value;
			min_pos = pos;
		}
		if (curr->value > *max_val)
			*max_val = curr->value;
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

int	insert_pos(t_node *stack_a, int value)
{
	t_node	*curr;
	int		pos;
	int		min_val;
	int		max_val;
	int		min_pos;

	min_val = INT_MAX;
	max_val = INT_MIN;
	min_pos = smallest_or_largest(stack_a, &min_val, &max_val);
	if (value < min_val || value > max_val)
		return (min_pos);
	pos = 0;
	curr = stack_a;
	while (curr->next)
	{
		if (curr->value < value && value < curr->next->value)
			return (pos + 1);
		curr = curr->next;
		pos++;
	}
	if (stack_a->value > value && curr->value < value)
		return (0);
	return (pos + 1);
}
