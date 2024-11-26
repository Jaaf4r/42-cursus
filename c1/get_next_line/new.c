#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char		*bf;
	static char	*st;
	ssize_t		rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bf = malloc(BUFFER_SIZE + 1);
	if (!bf)
		return (NULL);
	while ((rd = read(fd, bf, BUFFER_SIZE)))
	{
		bf[rd] = '\0';
		if (!st)
			st = ft_strdup("");
		st = ft_strjoin(st, bf);
		if (!st)
			return (NULL);
		if (ft_strchr(st, '\n'))
			break ;
	}
	free(bf);
	if (rd < 0 || (rd == 0 && (!st || !*st)))
		return (free(st), st = NULL, NULL);
	ssize_t	newl_pos = 0;
	while (st[newl_pos] && st[newl_pos] != '\n')
		newl_pos++;
	char	*line = malloc(newl_pos + 1 + (st[newl_pos] == '\n'));
	if (!line)
		return (free(st), NULL);
	ssize_t	i = 0;
	while (i < newl_pos)
	{
		line[i] = st[i];
		i++;
	}
	if (st[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	char	*remain = ft_strdup(st + newl_pos + (st[newl_pos] == '\n'));
	free(st);
	st = remain;
	return (line);
}

int	main(int ac, char **av)
{
	(void)ac;
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}