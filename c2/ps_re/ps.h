#ifndef PS_H
#define PS_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)
#define LONG_MAX 9223372036854775807L
#define LONG_MIN (-9223372036854775807L - 1)

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

/* STRING FUNCTIONS */
int		count_words(char *s, char c);
char	**ft_split(char *s, char c);
void	free_split(char **ss);
char	*ft_strdup(char *s);
long	ft_atoi(char *s);
int		ft_strcmp(char *s1, char *s2);

/* INPUT PARSING */
int		is_invalid_num(char *s);
int		is_dup(char **all_val);
char	**parse_input(char **av);

/* LINKEDLIST FUNCTIONS */
t_node	*create_node(int value);
void	ft_lstadd_front(t_node **lst, t_node *node);
void	free_stack(t_node *stack);

/* TESTING FUNCTIONS */
void	print_stack(t_node *stack);

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

/*  */

#endif