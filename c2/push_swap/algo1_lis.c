#include "ps.h"

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

int	*find_lis(t_node *stack_a, int *length)
{
	int	i;
	int	j;
	int	stack_size;
	int	*arr;
	int	*lis_length;
	int	*backtrack;

	stack_size = ft_lstsize(stack_a);
	arr = malloc(sizeof(int) * stack_size);
	lis_length = malloc(sizeof(int) * stack_size);
	backtrack = malloc(sizeof(int) * stack_size);
	if (!arr)
		return (NULL);
	else if (!lis_length)
		return (free(arr), NULL);
	else if (!backtrack)
		return (free(arr), free(lis_length), NULL);
	i = 0;
	while (i < stack_size)
	{
		arr[i] = stack_a->value;
		lis_length[i] = 1;
		backtrack[i] = -1;
		i++;
		stack_a = stack_a->next;
	}
	*length = lis_length[0];
	int	backtrack_i = 0;
	i = 1;
	while (i < stack_size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis_length[i] < lis_length[j] + 1)
			{
				lis_length[i] = lis_length[j] + 1;
				backtrack[i] = j;
			}
			j++;
		}
		if (*length < lis_length[i])
		{
			*length = lis_length[i];
			backtrack_i = i;
		}
		i++;
	}
	int	seq_i = *length - 1;
	int	*seq = malloc(sizeof(int) * backtrack_i);
	if (!seq)
		return (free(arr), free(lis_length), free(backtrack), NULL);
	while (backtrack_i != -1)
	{
		seq[seq_i--] = arr[backtrack_i];
		backtrack_i = backtrack[backtrack_i];
	}
	free(arr);
	free(lis_length);
	free(backtrack);
	return (seq);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				int	tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_pivot(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
		i++;
	return (i);
}

int	*get_non_lis(t_node *stack_a)
{
	int	i;
	int	stack_size;
	int	*sorted_arr;
	int	pivot;

	stack_size = ft_lstsize(stack_a);
	sorted_arr = malloc(sizeof(int) * stack_size);
	if (!sorted_arr)
		return (NULL);
	i = 0;
	while (i < stack_size)
	{
		sorted_arr[i] = stack_a->value;
		i++;
		stack_a = stack_a->next;
	}
	bubble_sort(sorted_arr, stack_size);
	pivot = find_pivot(sorted_arr, stack_size);

	return (sorted_arr);
}
