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

void	testing()
{
	srand(time(NULL));

	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

	int	i = 0;
	while (i < 5)
	{
		ft_lstaddfront(&stack_a, create_node(rand() % 100));
		i++;
	}
	i = 0;
	while (i < 5)
	{
		ft_lstaddfront(&stack_b, create_node(rand() % 100));
		i++;
	}
	printf("\nstack a:\n");
	print_stack(stack_a);
	printf("stack b:\n");
	print_stack(stack_b);
	printf("\n\nsa:\n");
	sa(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nsb:\n");
	sb(&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nss:\n");
	ss(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\npa:\n");
	pa(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\npb:\n");
	pb(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nra:\n");
	ra(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nrb:\n");
	rb(&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nrr:\n");
	rr(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nrra:\n");
	rra(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nrrb:\n");
	rrb(&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n\nrrr:\n");
	rrr(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n");
}

int	main()
{
	testing();
}
