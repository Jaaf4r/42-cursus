#include "get_next_line_bonus.h"

static char	*readfd(int fd, char *stock)
{
	char	*buf;
	ssize_t	rdret;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		rdret = read(fd, buf, BUFFER_SIZE);
		if (rdret <= 0)
			break ;
		buf[rdret] = '\0';
		if (!stock)
			stock = ft_strdup("");
		tmp = stock;
		stock = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stock || ft_strchr(stock, '\n'))
			break ;
	}
	free(buf);
	if (rdret < 0 || (rdret == 0 && (!stock || !*stock)))
		return (free(stock), stock = NULL, NULL);
	return (stock);
}

static char	*get_line(char *stock)
{
	ssize_t	newl_pos;
	char	*line;
	ssize_t	i;

	if (!stock || !*stock)
		return (NULL);
	newl_pos = 0;
	while (stock[newl_pos] && stock[newl_pos] != '\n')
		newl_pos++;
	line = malloc(newl_pos + (stock[newl_pos] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < newl_pos)
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[newl_pos] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_stock(char *stock)
{
	ssize_t	newl_pos;
	char	*remain;

	if (!stock || !*stock)
		return (NULL);
	newl_pos = 0;
	while (stock[newl_pos] && stock[newl_pos] != '\n')
		newl_pos++;
	remain = ft_strdup(stock + newl_pos + (stock[newl_pos] == '\n'));
	free(*stock);
	*stock = remain;
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stocks[MAX_FD] = {NULL};
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stocks[fd] || !ft_strchr(stocks[fd], '\n'))
	{
		stocks[fd] = readfd(fd, stocks[fd]);
		if (!stocks[fd])
			return (NULL);
	}
	line = get_line(stocks[fd]);
	stocks[fd] = update_stock(stocks[fd]);
	if (!line)
	{
		stocks[fd] = NULL;
		return (NULL);
	}
	return (line);
}

/*# include <stdio.h>
# define MAX_FILES 3

int	main(int ac, char **av)
{
	char	*line;
	int		fd[MAX_FILES];
	int		i;
	int		files_open;
	int		eof_reached[MAX_FILES];

	if (ac < 2 || ac > MAX_FILES + 1)
	{
		printf("Usage: %s <file1> <file2> <file3>\n", av[0]);
		return (1);
	}

	files_open = ac - 1;
	for (i = 0; i < files_open; i++)
	{
		fd[i] = open(av[i + 1], O_RDONLY);
		if (fd[i] < 0)
		{
			printf("Error opening file: %s\n", av[i + 1]);
			return (1);
		}
		eof_reached[i] = 0;
	}

	i = 0;
	while (files_open > 0)
	{
		if (eof_reached[i] == 0)
		{
			line = get_next_line(fd[i]);
			if (line)
			{
				printf("File %d: %s", i + 1, line);
				free(line);
			}
			else
			{
				close(fd[i]);
				eof_reached[i] = 1;
				files_open--;
			}
		}

		i = (i + 1) % (ac - 1);
	}

	return (0);
}*/
//
// #include <stdio.h>
// int main()
// {
// 	int		fd, fd2, fd3;
// 	char	*line;

// 	fd = open("a.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	fd2 = open("b.txt", O_RDONLY);
// 	line = get_next_line(fd2);
// 	printf("%s\n", line);
// 	free(line);

// 	fd3 = open("c.txt", O_RDONLY);
// 	line = get_next_line(fd3);
// 	printf("%s\n", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// }