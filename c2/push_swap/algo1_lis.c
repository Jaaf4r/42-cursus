#include "ps.h"

int	is_sorted(t_node *stack)
{
	t_node	*curr;

	if (!stack || !stack->next)
		return (1);

	curr = stack;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	*get_lis(t_node *stack_a, int *lis_length)
{
	if (!stack_a)
		return (NULL);

	t_node	*tmp = stack_a;
	int		n = ft_lstsize(stack_a);
	int		*arr = malloc(sizeof(int) * n);
	int		*length = malloc(sizeof(int) * n);
	int		*subs = malloc(sizeof(int) * n);
	if (!arr || !length || !subs)
		return (NULL);

	for (int i = 0; i < n; i++)
	{
		arr[i] = tmp->value;
		length[i] = 1;
		subs[i] = -1;
		tmp = tmp->next;
	}

	int	i = 1;
	while (i < n)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && length[i] < length[j] + 1)
			{
				length[i] = length[j] + 1;
				subs[i] = j;
			}
		}
		i++;
	}
	int	maxlength = 0;
	int	maxIndx = 0;
	i = 0; 
	while (i < n)
	{
		if (maxlength < length[i])
		{
			maxlength = length[i];
			maxIndx = i;
		}
		i++;
	}

	int	*seq = malloc(sizeof(int) * maxlength);
	if (!seq)
		return (NULL);
	int	seq_index = maxlength - 1;
	int	subs_backtrack = maxIndx;
	while (subs_backtrack != -1)
	{
		seq[seq_index--] = arr[subs_backtrack];
		subs_backtrack = subs[subs_backtrack];
	}
	free(arr);
	free(subs);
	free(length);
	*lis_length = maxlength;
	return (seq);
}

int	is_lis(int value, int *lis, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (lis[i] == value)
			return (1);
	}
	return (0);
}

int	find_pivot(t_node *stack_a)
{
	int		n = ft_lstsize(stack_a);
	int		*arr = malloc(sizeof(int) * n);
	if (!arr)
		return (0);

	t_node	*tmp = stack_a;
	for (int i = 0; i < n; i++)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	bubble_sort(arr, n);
	int	pivot = arr[n / 2];
	free(arr);
	return (pivot);
}

void	bubble_sort(int	*arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int	tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void	push_nonlis(t_node **stack_a, t_node **stack_b, int *lis, int lis_length)
{
	int	pivot = find_pivot(*stack_a);
	int	size = ft_lstsize(*stack_a);

	while (size--)
	{
		if (is_lis((*stack_a)->value, lis, lis_length))
			ra(stack_a);
		else
		{
			if ((*stack_a)->value > pivot)
				pb(stack_a, stack_b);
			else
			{
				pb(stack_a, stack_b);
				rrb(stack_b);
			}
		}
	}
}
