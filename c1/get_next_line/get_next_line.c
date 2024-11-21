#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		else
		{
			if (bytes_read < BUFFER_SIZE)
				buffer[bytes_read] = '\0';
			if (ft_strchr(buffer, '\n'))
				break ;
			stock = ft_strdup(buffer);
		}
	}

	return (NULL);
}

int main()
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);

}
