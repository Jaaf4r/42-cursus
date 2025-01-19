#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

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
void	ft_lstadd_back(t_node **lst, t_node *node);
void	free_stack(t_node *stack);
int		ft_lstsize(t_node *stack);

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

/* ALGO FUNCTIONS */
int		is_sorted(t_node *stack);
int		*find_lis(t_node *stack, int *length);
void	bubble_sort(int *arr, int size);
int		find_pivot(int *arr, int size);
int		get_non_lis(t_node *stack_a);
void	pushNonLisTo_stack_b(t_node **stack_a, t_node **stack_b);



#endif