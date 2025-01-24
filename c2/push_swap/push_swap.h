/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:11 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 22:28:20 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_calc {
	int	size_a;
	int	size_b;
	int	best_cost;
	int	best_a_pos;
	int	best_b_pos;
	int	index;
	int	pos_in_a;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}	t_calc;

/* MAIN FUNCTION ^-^ */
int		main(int ac, char **av);

/* INPUT PARSING */
int		is_empty_arg(char *s);
int		is_invalid_num(char *s);
char	*normlize_num(char *s);
int		is_dup(char **all_val);
char	**fill_all_val(char **av, char **all_val);
char	**parse_input(char **av);

/* STRING FUNCTIONS */
int		count_words(char *s, char c);
char	**ft_split(char *s, char c);
void	free_all(char **ss);
char	*ft_strdup(char *s);
bool	ft_atoi(char *s, long *total);
int		ft_strcmp(char *s1, char *s2);

/* LINKEDLIST FUNCTIONS */
t_node	*create_node(int value);
void	ft_lstadd_back(t_node **lst, t_node *node);
void	free_stack(t_node *stack);
int		ft_lstsize(t_node *stack);

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
int		is_reversed(t_node *stack_a);
// STEP [1]:
int		*find_lis(t_node *stack, int *length);
void	quick_sort(int *arr, int left, int right);
void	push_nonlis_to_stack_b(t_node **stack_a, t_node **stack_b);
// STEP [2]:
int		insert_pos(t_node *stack_a, int value);
int		calculate_rot_cost(int stack_size, int index);
int		abs_val(int x);
int		max(int a, int b);
// STEP [3]:
void	push_to_a(t_node **stack_a, t_node **stack_b);
// STEP [4]:
void	rotate_stack_a(t_node **stack_a);

#endif
