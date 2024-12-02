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

ssize_t	readfd(t_list *node, int fd)
{
	char	*tmpbuf;
	ssize_t	b_read;
	char	*joinbuf;

	tmpbuf = malloc(BUFFER_SIZE + 1);
	if (!tmpbuf)
		return (-1);
	b_read = read(fd, tmpbuf, BUFFER_SIZE);
	if (b_read > 0)
	{
		tmpbuf[b_read] = '\0';
		joinbuf = ft_strjoin(node->buf, tmpbuf);
		if (!joinbuf)
			return (free(tmpbuf), -1);
		free(node->buf);
		node->buf = joinbuf;
	}
	free(tmpbuf);
	return (b_read);
}

void	dellnode(t_list **head, int fd)
{
	t_list	*current;
	t_list	*prev;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->buf);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

char	*get_line(char **buffer)
{
	char	*newl_pos;
	char	*new_buffer;
	char	*line;

	if (!*buffer || !**buffer)
		return (NULL);
	newl_pos = ft_strchr(*buffer, '\n');
	if (newl_pos)
	{
		line = ft_strndup(*buffer, newl_pos - *buffer + 1);
		new_buffer = ft_strdup(newl_pos + 1);
		free(*buffer);
		*buffer = new_buffer;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*stock;
	char			*line;
	ssize_t			b_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = get_node(&stock, fd);
	if (!stock)
		return (NULL);
	b_read = readfd(stock, fd);
	if (b_read < 0)
		return (dellnode(&stock, fd), NULL);
	line = get_line(&stock->buf);
	if (!line || b_read == 0)
		return (dellnode(&stock, fd), NULL);
	return (line);
}
