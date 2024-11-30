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
t_list	*get_node(t_list **head, int fd);
char	*readfd(char *buf, int fd);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);

#endif