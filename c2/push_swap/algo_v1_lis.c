/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v1_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:30:19 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 16:30:20 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_arrays(t_node *stack_a, int *arr, int *lis_len, int *backtrack)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		arr[i] = stack_a->value;
		lis_len[i] = 1;
		backtrack[i] = -1;
		i++;
		stack_a = stack_a->next;
	}
}

static void	find_lis_sub(int *arr, int *lis_len, int *backtrack, int stack_size)
{
	int	i;
	int	j;

	i = 1;
	while (i < stack_size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis_len[i] < lis_len[j] + 1)
			{
				lis_len[i] = lis_len[j] + 1;
				backtrack[i] = j;
			}
			j++;
		}
		i++;
	}
}

static void	update_length(int stack_size, int *length, int *lis_length
, int *backtrack_i)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if (*length < lis_length[i])
		{
			*length = lis_length[i];
			*backtrack_i = i;
		}
		i++;
	}
}

static int	*get_final_lis(int *arr, int *backtrack, int len, int backtrack_i)
{
	int	*seq;
	int	seq_i;

	seq = malloc(sizeof(int) * len);
	if (!seq)
		return (NULL);
	seq_i = len - 1;
	while (backtrack_i != -1)
	{
		seq[seq_i--] = arr[backtrack_i];
		backtrack_i = backtrack[backtrack_i];
	}
	return (seq);
}

int	*find_lis(t_node *stack_a, int *length)
{
	int	stack_size;
	int	*arr[3];
	int	backtrack_i;
	int	*seq;

	stack_size = ft_lstsize(stack_a);
	arr[0] = malloc(sizeof(int) * stack_size);
	arr[1] = malloc(sizeof(int) * stack_size);
	arr[2] = malloc(sizeof(int) * stack_size);
	if (!arr[0] || !arr[1] || !arr[2])
		return (free(arr[0]), free(arr[1]), free(arr[2])
			, arr[0] = NULL, arr[1] = NULL, arr[2] = NULL, NULL);
	init_arrays(stack_a, arr[0], arr[1], arr[2]);
	find_lis_sub(arr[0], arr[1], arr[2], stack_size);
	*length = arr[1][0];
	backtrack_i = 0;
	update_length(stack_size, length, arr[1], &backtrack_i);
	seq = get_final_lis(arr[0], arr[2], *length, backtrack_i);
	return (free(arr[0]), free(arr[1]), free(arr[2])
		, arr[0] = NULL, arr[1] = NULL, arr[2] = NULL, seq);
}
