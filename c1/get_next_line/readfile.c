#include "get_next_line.h"

int main()
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	int		fd;

	fd = -1; // open("text.txt", O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		return (NULL);
	}

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
	}

	if (bytes_read == -1)
		perror("Error reading file");

	close(fd);

}
