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
	pivot = get_stack_pivot(*stack_a);
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
