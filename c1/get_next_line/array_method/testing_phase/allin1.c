#include "../get_next_line.h"

char    *get_next_line(int fd)
{
	char		*buf;
	ssize_t		rdret;
	static char	*stock = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while ((rdret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rdret] = '\0';
		if (!stock)
			stock = ft_strdup("");
		char	*tmp = stock;
		stock = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stock)
			return (free(buf), NULL);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	free(buf);
	if (rdret < 0 || (rdret == 0 && (!stock || !*stock)))
		return (free(stock), NULL);

	ssize_t	newl_pos = 0;
	while (stock[newl_pos] && stock[newl_pos] != '\n')
		newl_pos++;
	char	*line = malloc(newl_pos + (stock[newl_pos] == '\n') + 1);
	if (!line)
		return (free(stock), NULL);
	ssize_t	i = 0;
	while (i < newl_pos)
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[newl_pos] == '\n')
		line[i++] = '\n';
	line[i] = '\0';

	char	*remain = ft_strdup(stock + newl_pos + (stock[newl_pos] == '\n'));
	free(stock);
	stock = remain;
	return (line);
}

int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
