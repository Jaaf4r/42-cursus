#include "get_next_line.h"

t_list	*get_node(t_list **head, int fd)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = malloc(sizeof(t_list));
	if (!current)
		return (NULL);
	current->fd = fd;
	current->buf = NULL;
	current->next = *head;
	*head = current;
	return (current);
}

char	*readfd(char *buf, int fd)
{
	char	*tmpbuf;
	ssize_t	b_read;

	tmpbuf = malloc(BUFFER_SIZE + 1);
	if (!tmpbuf)
		return (NULL);
	while (1)
	{
		b_read = read(fd, tmpbuf, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		
	}
}

char	*get_next_line(int fd)
{
	static t_list	*stock;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock->buf = get_node(&stock, fd);
	if (!stock->buf)
		return (NULL);
	stock->buf = 



	return (line);
}
