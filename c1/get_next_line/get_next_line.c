#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*reader;
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return(NULL);

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE) > 0))
	{}
}
