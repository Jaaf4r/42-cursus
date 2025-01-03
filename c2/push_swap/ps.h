#ifndef PS_H
#define PS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

/* FT_PRINTF */
int	ft_char_str(int c, char *s);
int	ft_digit(unsigned long n, int base, int uplowcase, int is_signed);
int	handle_format(char format, va_list args);
int	process_format(const char **format, va_list args);
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


#endif
