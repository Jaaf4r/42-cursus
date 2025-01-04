#include "ps.h"

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
		printf("\n");
	}
	else
		ft_printf("EMPTY LIST\n");
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
	ft_printf("\nstack a:\n");
	print_stack(stack_a);
	ft_printf("stack b:\n");
	print_stack(stack_b);
	ft_printf("\n\nsa:\n");
	sa(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nsb:\n");
	sb(&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nss:\n");
	ss(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\npa:\n");
	pa(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\npb:\n");
	pb(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nra:\n");
	ra(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nrb:\n");
	rb(&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nrr:\n");
	rr(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nrra:\n");
	rra(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nrrb:\n");
	rrb(&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n\nrrr:\n");
	rrr(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");
}

/*int	main()
{
	testing();
}*/
