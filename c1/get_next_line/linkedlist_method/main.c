#include <fcntl.h>  // For open()
#include <unistd.h> // For close()
#include <stdio.h>  // For printf()
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}
