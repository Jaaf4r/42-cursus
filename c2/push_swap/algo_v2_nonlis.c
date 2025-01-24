/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2_nonlis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:24:49 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/24 22:25:03 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	quick_sort(sorted_arr, 0, stack_size - 1);
	pivot = sorted_arr[stack_size / 2];
	free(sorted_arr);
	return (pivot);
}

static int	is_in_lis(int value, int length, int *seq)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = length - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (value == seq[mid])
			return (1);
		if (value > seq[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (0);
}

static int	count_below_pivot(t_node *stack, int *seq, int len, int pivot)
{
	int		count;
	t_node	*curr;
	int		size;
	int		i;

	count = 0;
	curr = stack;
	size = ft_lstsize(stack);
	i = 0;
	while (i < size)
	{
		if (!is_in_lis(curr->value, len, seq) && curr->value <= pivot)
			count++;
		curr = curr->next;
		i++;
	}
	return (count);
}

static void	handle_operations(t_node **stack_a, t_node **stack_b
, int pivot, int *below_pivot)
{
	pb(stack_a, stack_b);
	write(1, "pb\n", 3);
	if ((*stack_b)->value <= pivot && *below_pivot > 1)
	{
		rb(stack_b);
		write(1, "rb\n", 3);
		(*below_pivot)--;
	}
}

void	push_nonlis_to_stack_b(t_node **stack_a, t_node **stack_b)
{
	int		*seq;
	int		length;
	int		stack_size;
	int		below_pivot;
	int		pivot;

	seq = find_lis(*stack_a, &length);
	if (!seq)
		return ;
	pivot = get_stack_pivot(*stack_a);
	below_pivot = count_below_pivot(*stack_a, seq, length,
			get_stack_pivot(*stack_a));
	stack_size = ft_lstsize(*stack_a);
	while (stack_size--)
	{
		if (!is_in_lis((*stack_a)->value, length, seq))
			handle_operations(stack_a, stack_b, pivot, &below_pivot);
		else
		{
			ra(stack_a);
			write(1, "ra\n", 3);
		}
	}
	free(seq);
}
