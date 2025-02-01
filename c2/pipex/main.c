#include "pipex.h"
#include <string.h>

static int	valid_arg_files(char **av, int i)
{
	int	fd;

	if (i == 1 && (!av[i] || access(av[i], F_OK) != 0))
		return (perror(av[i]), 0);
	else if (i == 4 && !av[i])
	{
		fd = open(av[i], O_RDWR | O_CREAT, 0644);
		if (fd == -1)
			return (perror(av[i]), 0);
		close (fd);
	}
	return (1);
}

static int	valid_arg_commands(char **av, int i)
{
	int	status;

	status = system(av[i]);
	if (status == -1)
		return (system("echo $0"), perror(": command not found: %s\n"), 0);
	return (1);
}

static int	valid_args(char **av)
{
	if (!valid_arg_files(av, 1) || !valid_arg_files(av, 2)
		|| !valid_arg_commands(av, 3) || !valid_arg_files(av, 4))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 5)
		return (1);
	if (!valid_args(av))
		return (printf("shi haja ghalat\n"), 1);
	printf("kolshi tamam\n");
}
