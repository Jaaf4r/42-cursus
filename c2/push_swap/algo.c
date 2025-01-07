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

void	find_lis(t_node *stack_a)
{
	if (!stack_a)
		return;

	t_node	*tmp = stack_a;
	int		n = ft_lstsize(stack_a);
	int		*arr = malloc(sizeof(int) * n);
	int		*length = malloc(sizeof(int) * n);
	int		*subs = malloc(sizeof(int) * n);
	if (!arr || !length || !subs)
		return;

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
			if (arr[i] > arr[j] && length[j] < length[i] + 1)
			{
				length[i] = length[j] + 1;
				subs[i] = j;
			}
		}
		i++;
	}
	int	maxlength = 0;
	i = 0; 
	while (i < n)
	{
		if (maxlength < length[i])
			maxlength = length[i];
		i++;
	}
	int	subs_backtrack = i; // corresponding index to i (index of biggest value)
	int	*seq = malloc(sizeof(int) * n);
	if (!seq)
		return;
	int	seq_index = maxlength - 1;
	while (subs_backtrack != 0)
	{
		seq[seq_index] = subs[subs_backtrack];
		subs_backtrack = subs[subs_backtrack];
	}
	
	// ---------------------------------------------

	for (int i = 0; i < n; i++)
	{
		ft_printf("%d       ", length[i]);
	}
	ft_printf("\n");
	for (int i = 0; i < n; i++)
	{
		ft_printf("%d       ", subs[i]);
	}
	ft_printf("\n\n");

	for (int i = 0; i < maxlength; i++)
	{
		ft_printf("%d       ", seq[i]);
	}
	ft_printf("\n");
}
