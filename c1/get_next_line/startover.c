#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*tmpbuf;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmpbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmpbuf)
		return (free(tmpbuf), NULL);
	while ((bytes_read = read(fd, tmpbuf, BUFFER_SIZE)) > 0)
	{
		tmpbuf[bytes_read] = '\0';
		if (!stock)
			stock = ft_strdup("");
		stock = ft_strjoin(stock, tmpbuf);
		if (!stock)
			return (free(stock), stock = NULL, NULL);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	if (bytes_read < 0 || (bytes_read == 0 && (!stock || !*stock)))
		return (free(stock),free(tmpbuf), stock = NULL, NULL);

	ssize_t	newl_pos = 0;
	while (stock[newl_pos] != '\n')
		newl_pos++;
	char	*line = (char *)malloc(sizeof(char) * (newl_pos + 1));
	if (!line)
		return (NULL);
	line[newl_pos] = '\0';
	ssize_t	i = 0;
	while (i < newl_pos)
	{
		line[i] = stock[i];
		i++;
	}
	char	*remain = ft_strdup(stock + newl_pos + 1);
	free(stock);
	stock = remain;
	free(tmpbuf);
	return (line);
}

int	main(int ac, char **av)
{
	(void)ac;
	char	*s;
	int		fd;

	fd = open(av[1], O_RDONLY);

	s = get_next_line(fd);
	printf("%s \n", s);
	free(s);
	// while ((s = get_next_line(fd)))
	// {
	// 	printf("%s \n", s);
	// 	free(s);
	// }
	return (0);
}