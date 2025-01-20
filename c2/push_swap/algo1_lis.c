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
	int	*seq = malloc(sizeof(int) * (*length));
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

int	get_non_lis(t_node *stack_a)
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
	quickSort(sorted_arr, 0, stack_size);
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
				printf("pb\n");
			}
			else
			{
				pb(stack_a, stack_b);
				rrb(stack_b);
				printf("pb + rrb\n");
			}
		}
		i++;
	}
	free(seq);
}
