/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2_nonlis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:21:53 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 16:34:22 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pivot(int *arr, int size)
{
	int	i;
	int	pivot_num;

	i = 0;
	while (i < size / 2)
	{
		pivot_num = arr[i];
		i++;
	}
	return (pivot_num);
}

static int	get_stack_pivot(t_node *stack_a)
{
	int		i;
	int		stack_size;
	int		*sorted_arr;
	int		pivot;
	t_node	*tmp;

	stack_size = ft_lstsize(stack_a);
	sorted_arr = malloc(sizeof(int) * stack_size);
	if (!sorted_arr)
		return (0);
	i = 0;
	tmp = stack_a;
	while (i < stack_size)
	{
		sorted_arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	quickSort(sorted_arr, 0, stack_size - 1);
	pivot = find_pivot(sorted_arr, stack_size);
	free(sorted_arr);
	return (pivot);
}

static int	is_in_lis(int value, int length, int *seq)
{
	int	j;

	j = 0;
	while (j < length)
	{
		if (value == seq[j])
			return (1);
		j++;
	}
	return (0);
}

static void	which_operations(t_node **stack_a, t_node **stack_b)
{
	int	pivot;

	pivot = get_stack_pivot(*stack_a);
	if ((*stack_a)->value > pivot)
	{
		pb(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	else
	{
		pb(stack_a, stack_b);
		rrb(stack_b);
		write(1, "pb\n", 3);
		write(1, "rrb\n", 4);
	}
}

void	push_nonlis_to_stack_b(t_node **stack_a, t_node **stack_b)
{
	int		*seq;
	int		length;
	int		i;
	int		stack_size;

	seq = find_lis(*stack_a, &length);
	if (!seq)
		return ;
	i = 0;
	stack_size = ft_lstsize(*stack_a);
	while (i < stack_size)
	{
		if (is_in_lis((*stack_a)->value, length, seq))
			ra(stack_a);
		else
			which_operations(stack_a, stack_b);
		i++;
	}
	free(seq);
}
