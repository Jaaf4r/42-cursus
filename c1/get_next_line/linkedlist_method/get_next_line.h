#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NULL ((void *)0)

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}	t_list;

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

t_list	*get_node(t_list **head, int fd);
ssize_t	readfd(t_list *node, int fd);
void	dellnode(t_list **head, int fd);
char	*get_line(char **buffer);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t size);

#endif