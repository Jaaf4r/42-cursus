#include "get_next_line.h"

int main()
{
	char	*buffer;
	ssize_t	bytes_read;
	int		fd;

	// fd = open("text.txt", O_RDWR | O_CREAT, 0644);
	// if (fd < 0 || BUFFER_SIZE < 0)
	// 	return (0);
	// // write(fd, "anrgoiajgojafpoekwfjwaoij", 26);
	// close(fd);

	// while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	// {
	// 	buffer[bytes_read] = '\0';
	// 	printf("%s", buffer);
	// 	if (strchr(buffer, '\n'))
	// 		break ;
	// }

	fd = open("text.txt", O_RDWR | O_CREAT | O_TRUNC , 0664);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	write(fd, "01234567890", 11);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0)
		return (0);
	write(1, buffer, bytes_read);

	close(fd);

}
