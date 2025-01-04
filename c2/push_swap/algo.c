#include "ps.h"

int	is_sorted(t_node *stack)
{
	t_node	*curr = stack;
	t_node	*curr2 = stack->next;

	if (curr && curr2)
	{
		while (curr2->next)
		{
			if (curr->value < curr2->value)
			{
				curr2 = curr2->next;		
				curr = curr->next;
			}
			else
				return (ft_printf("Get to work\n"), 0);
		}
		return (ft_printf("Shit already sorted bruh\n"), 0);
	}
	return (ft_printf("aight nuthin here to sort, ma nigga\n"), 0);
}
