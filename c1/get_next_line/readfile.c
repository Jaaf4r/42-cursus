#include "get_next_line.h"

int main()
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		fd;

	fd = open("text.txt", O_RDONLY | O_CREAT, 0644);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
		if (strchr(buffer, '\n'))
			break ;
	}

	if (bytes_read < 0)
		return (0);

	close(fd);

}
