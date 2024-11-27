/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaafar <jaafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:27:03 by jaafar            #+#    #+#             */
/*   Updated: 2024/11/27 12:17:29 by jaafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	update_stock(char **stock)
{
	ssize_t	newl_pos;
	char	*remain;

	newl_pos = 0;
	while ((*stock)[newl_pos] && (*stock)[newl_pos] != '\n')
		newl_pos++;
	remain = ft_strdup(*stock + newl_pos + ((*stock)[newl_pos] == '\n'));
	free(*stock);
	*stock = remain;
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
	update_stock(&stocks[fd]);
	return (line);
}
