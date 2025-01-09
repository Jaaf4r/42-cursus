#ifndef PS_H
#define PS_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <stdarg.h>

#define INT_MAX 0x7fffffff
#define INT_MIN (-0x7fffffff - 1)
#define LLONG_MAX 0x7fffffffffffffffLL
#define LLONG_MIN (-0x7fffffffffffffffLL -1LL)

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

/* FT_PRINTF */
int	ft_printf(const char *format, ...);

/* STRING FUNCTIONS */
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
void	free_split(char **v);

/* INPUT PARSING */
char	**parse_input(char **av);

/* HELPER FUNCTIONS */
t_node	*create_node(int value);
void	ft_lstaddfront(t_node **lst, t_node *node);
int		ft_lstsize(t_node *stack);
void	print_stack(t_node *head);
void	free_stack(t_node *stack);

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
int		is_sorted(t_node *head);
int		*get_lis(t_node *stack_a, int *lis_length);
void	push_nonlis(t_node **stack_a, t_node **stack_b, int *lis, int lis_length);
int		find_pivot(t_node *stack_a);
void	bubble_sort(int	*arr, int n);


int		find_target_pos(t_node *stack_a, int value);
int		get_node_index(t_node *stack, int value);
int		calculate_moves(int stack_size, int index);
void	find_best_move(t_node *stack_a, t_node *stack_b, int *best_value, int *min_moves);


#endif
