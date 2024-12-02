/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:41:28 by jabouhni          #+#    #+#             */
/*   Updated: 2024/12/02 17:41:29 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (rdret < 0)
		return (free(stock), NULL);
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

	newl_pos = 0;
	while (stock[newl_pos] && stock[newl_pos] != '\n')
		newl_pos++;
	remain = ft_strdup(stock + newl_pos + (stock[newl_pos] == '\n'));
	free(stock);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = readfd(fd, stock);
	if (!stock)
		return (NULL);
	line = get_line(stock);
	stock = update_stock(stock);
	if (!line && (!stock || !*stock))
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	char	*line;
// 	int		fd;

// 	fd = open(av[1], O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// free(line);
// 	close(fd);
// }