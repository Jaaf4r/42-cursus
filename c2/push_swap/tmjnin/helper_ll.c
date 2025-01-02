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

void	sa(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		t_node	*first = *stack_a;
		t_node	*second = (*stack_a)->next;

		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
}

void	sb(t_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		t_node	*first = *stack_b;
		t_node	*second = (*stack_b)->next;

		first->next = second->next;
		second->next = first;
		*stack_b = second;
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (*stack_b)
	{
		t_node	*tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
	{
		t_node	*tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void	ra(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		t_node	*tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		t_node	*trav = *stack_a;

		while (trav->next)
			trav = trav->next;
		trav->next = tmp;
		tmp->next = NULL;
	}
}

void	ft_lstaddfront(t_node **lst, t_node *node)
{
	if (!node)
		return;
	node->next = *lst;
	*lst = node;
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

	ra(&head);
	curr = head;
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
