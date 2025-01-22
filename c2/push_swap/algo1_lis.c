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
	int	backtrack_i;
	int	i;
	int	j;

	backtrack_i = 0;
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

static void	update_length(int stack_size, int *length, int *lis_length, int *backtrack_i)
{
	int	i;
	int	size;

	i = 0;
	while (i < stack_size)
	{
		if (*length < lis_length[i])
		{
			*length = lis_length[i];
			backtrack_i = i;
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
	int	*arr;
	int	*lis_len;
	int	*backtrack;
	int	backtrack_i;
	int	*seq;

	stack_size = ft_lstsize(stack_a);
	arr = malloc(sizeof(int) * stack_size);
	lis_len = malloc(sizeof(int) * stack_size);
	backtrack = malloc(sizeof(int) * stack_size);
	if (!arr || !lis_len || !backtrack)
		return (free(arr), free(lis_len), free(backtrack), NULL);
	init_arrays(stack_a, arr, lis_len, backtrack);
	get_lis_sub(arr, lis_len, backtrack, stack_size);
	*length = lis_len[0];
	backtrack_i = 0;
	update_length(stack_size, length, lis_len, &backtrack_i);
	seq = get_final_lis(arr, backtrack, *length, backtrack_i);
	return (free(arr), free(lis_len), free(backtrack), seq);
}

int	find_pivot(int *arr, int size)
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

int	get_stack_pivot(t_node *stack_a)
{
	int	i;
	int	stack_size;
	int	*sorted_arr;
	int	pivot;

	stack_size = ft_lstsize(stack_a);
	sorted_arr = malloc(sizeof(int) * stack_size);
	if (!sorted_arr)
		return (0);
	i = 0;
	t_node	*tmp = stack_a;
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

void	pushNonLisTo_stack_b(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		stack_size;
	int		*seq;
	int		pivot;
	int		length;
	t_node	*curr;

	seq = find_lis(*stack_a, &length);
	pivot = get_non_lis(*stack_a);
	if (!seq)
		return;
	i = 0;
	stack_size = ft_lstsize(*stack_a);
	while (i < stack_size)
	{
		curr = *stack_a;
		int	is_lis = 0;
		int	j = 0;
		while (j < length)
		{
			if (curr->value == seq[j])
			{
				is_lis = 1;
				break;
			}
			j++;
		}

		if (is_lis)
			ra(stack_a);
		else
		{
			if (curr->value > pivot)
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
		i++;
	}
	free(seq);
}
