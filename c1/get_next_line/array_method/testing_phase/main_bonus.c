#include "../get_next_line_bonus.h"

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
}
