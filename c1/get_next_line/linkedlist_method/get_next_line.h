#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}	t_list;

# define NULL ((void *)0)

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

#endif