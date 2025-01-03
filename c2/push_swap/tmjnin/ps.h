#ifndef PS_H
#define PS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct s_node {
	int		value;
	struct s_node	*next;
}	t_node;

/* LINKEDLIST HELPER FUNCTIONS */
t_node	*create_node(int value);
void	ft_lstaddfront(t_node **lst, t_node *node);
void	print_stack(t_node *head);

/* STACK OPERATIONS */
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

/* ALGO FUNCTIONS */


#endif
