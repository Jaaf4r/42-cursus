#include "ps.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_node **lst, t_node *node)
{
	if (!lst || !node)
		return;
	node->next = *lst;
	*lst = node;
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	ft_lstsize(t_node *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		c++;
		stack = stack->next;
	}
	return (c);
}
