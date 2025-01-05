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

void	ft_lstaddfront(t_node **lst, t_node *node)
{
	if (!node)
		return;
	node->next = *lst;
	*lst = node;
}

void	print_stack(t_node *head)
{
	if (head)
	{
		t_node	*curr = head;
		while (curr)
		{
			if (curr->next)
				ft_printf("[%d] -> ", curr->value);
			else
				ft_printf("[%d] .", curr->value);
			curr = curr->next;
		}
		ft_printf("\n");
	}
	else
		ft_printf("EMPTY LIST\n");
}

void	free_stack(t_node *stack)
{
    t_node *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
