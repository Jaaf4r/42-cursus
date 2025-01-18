#include "ps.h"

int	*find_lis(t_node *stack)
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
	if (!lis_arr || !lis_length || !backtrack)
		return (1);
	i = 0;
	while (stack->next)
	{
		lis_arr[i] = stack->value;
		lis_length[i] = 1;
		backtrack[i] = -1;
		i++;
		stack = stack->next;
	}
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
		i++;
	}
}
