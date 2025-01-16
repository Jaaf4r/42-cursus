#ifndef PS_H
#define PS_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)
#define LONG_MAX 9223372036854775807L
#define LONG_MIN (-9223372036854775807L - 1)

int		count_words(char *s, char c);
char	**ft_split(char *s, char c);
void	free_split(char **ss);
char	*ft_strdup(char *s);
long	ft_atoi(char *s);
int		ft_strcmp(char *s1, char *s2);

int	is_invalid_num(char *s);
int	is_dup(char **all_val);

char	**parse_input(char **av);

#endif