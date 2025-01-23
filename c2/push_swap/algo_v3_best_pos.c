#include "push_swap.h"

int	insert_pos(t_node *stack_a, int value)
{
	t_node	*curr;
	int		pos;
	int		min_pos = 0;
	int		min_value = INT_MAX;
	int		max_value = INT_MIN;

	curr = stack_a;
	pos = 0;
	while (curr)
	{
		if (curr->value < min_value)
		{
			min_value = curr->value;
			min_pos = pos;
		}
		if (curr->value > max_value)
			max_value = curr->value;
		curr = curr->next;
		pos++;
	}

	if (value < min_value || value > max_value)
		return (min_pos);

	curr = stack_a;
	pos = 0;
	while (curr->next)
	{
		if (curr->value < value && value < curr->next->value)
			return (pos + 1);
		curr = curr->next;
		pos++;
	}

	if (stack_a->value > value && curr->value < value)
		return (0);

	return (pos + 1);
}
