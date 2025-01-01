#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>

typedef struct s_pushswap
{
	void				*data;
	struct s_pushswap	*next;
	struct s_pushswap	*prev;
}   t_pushswap;



char    **ft_split(char const *s, char c);
char    *ft_strdup(const char *s);


# endif