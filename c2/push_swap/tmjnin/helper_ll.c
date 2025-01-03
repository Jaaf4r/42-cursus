#include "ai_ps.h"

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
	t_node	*curr = head;
	while (curr)
	{
		if (curr->next)
			printf("%d -> ", curr->value);
		else
			printf("%d .", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int	main()
{
	t_node	*head = NULL;

	t_node	*test = create_node(5);
	ft_lstaddfront(&head, test);
	test = create_node(19);
	ft_lstaddfront(&head, test);
	test = create_node(44);
	ft_lstaddfront(&head, test);
	test = create_node(100);
	ft_lstaddfront(&head, test);

	print_stack(head);
	rrb(&head);
	print_stack(head);
}
