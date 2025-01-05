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

int	find_lis(t_node **stack_a/*, t_node **stack_b*/)
{
	t_node	*curr;
	int		max_len;
	//t_node	*longest;

	if (!*stack_a)
    	return (0);
	curr = *stack_a;
	max_len = 0;
	while (curr->next)
	{
		t_node	*tmp = curr->next;
		int		len = 1;
		while (tmp)
		{
			if (curr->value < tmp->value)
				len++;
			tmp = tmp->next;
		}
		if (max_len < len)
			max_len = len;
		
		curr = curr->next;
	}
	return (max_len);
}
