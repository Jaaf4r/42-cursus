#include "ps.h"

int	is_sorted(t_node *stack)
{
	t_node	*curr;

	if (!stack || !stack->next)
		return (ft_printf("Nothing to sort!\n"), 1);

	curr = stack;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (ft_printf("Get to work\n"), 0);
		curr = curr->next;
	}
	return (ft_printf("Shit already sorted bruh\n"), 1);
}
