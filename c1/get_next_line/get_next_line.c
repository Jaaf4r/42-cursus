#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*tmp_buf;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	tmp_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buf)
		return (free(tmpbuf), NULL);
	while (1)
	{
		bytes_read = read(fd, tmp_buf, BUFFER_SIZE);

		tmp_buf[bytes_read] = '\0';
		stock = ft_strjoin(stock, tmp_buf);
		if (!stock)
		{
			free(tmp_buf);
			return (NULL);
		}
		if (strchr(stock, '\n'))
			break ;
	}
	free(tmp_buf);

	if (bytes_read < 0 || (bytes_read == 0 && (!stock || !*stock)))
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}

	newline_pos = strchr(stock, '\n');
	if (newline_pos)
	{
		char	*line = malloc(sizeof(char) * (new_line_pos + 1));
		if (!line)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		
	}
	else
	{

	}



	return (line);
}

int main()
{
	int		fd;
	char	*line

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
}
