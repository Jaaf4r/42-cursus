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

int	*find_lis(t_node *stack, int *length)
{
	int	i;
	int	j;
	int	stack_size;
	int	*lis_arr;
	int	*lis_length;
	int	*backtrack;

	stack_size = ft_lstsize(stack);
	lis_arr = malloc(sizeof(int) * stack_size);
	lis_length = malloc(sizeof(int) * stack_size);
	backtrack = malloc(sizeof(int) * stack_size);
	if (!lis_arr)
		return (NULL);
	else if (!lis_length)
		return (free(lis_arr), NULL);
	else if (!backtrack)
		return (free(lis_arr), free(lis_length), NULL);

	i = 0;
	while (i < stack_size)
	{
		lis_arr[i] = stack->value;
		lis_length[i] = 1;
		backtrack[i] = -1;
		i++;
		stack = stack->next;
	}
	*length = lis_length[0];
	int	backtrack_i = 0;
	i = 1;
	while (i < stack_size)
	{
		j = 0;
		while (j < i)
		{
			if (lis_arr[i] > lis_arr[j] && lis_length[i] < lis_length[j] + 1)
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
		return (free(lis_arr), free(lis_length), free(backtrack), NULL);
	while (backtrack_i != -1)
	{
		seq[seq_i--] = lis_arr[backtrack_i];
		backtrack_i = backtrack[backtrack_i];
	}
	free(lis_arr);
	free(lis_length);
	free(backtrack);
	return (seq);
}


