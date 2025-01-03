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
		t_node	*first = *stack_a;
		*stack_a = (*stack_a)->next;

		t_node	*last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	rb(t_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		t_node	*first = *stack_b;
		*stack_b = (*stack_b)->next;

		t_node	*last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		t_node	*last = *stack_a;
		t_node	*second_last = NULL;

		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
}

void	rrb(t_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		t_node	*last = *stack_b;
		t_node	*second_last = NULL;

		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
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
