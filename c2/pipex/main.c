#include "pipex.h"
#include <string.h>

static int	valid_arg_files(char **av, int i)
{
	int	fd;

	if (!av[i])
		return (0);
	if (i == 1 && access(av[i], F_OK) != 0)
		return (perror(av[i]), 0);
	else if (i == 4)
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
	char	**env;
	char	*full_path;
	int		k;

	env = ft_split(getenv("PATH"), ':');
	if (!env)
		return (0);
	k = 0;
	while (env[k])
	{
		full_path = ft_strjoin(env[k], "/");
		full_path = ft_strjoin(full_path, av[i]);
		if (access(full_path, X_OK) == 0)
			return (free(full_path), free_all(env), 1);
		free(full_path);
		k++;
	}
	return (free_all(env), printf("Command not found: %s\n", av[i]), 0);
}

static int	valid_args(char **av)
{
	if (!valid_arg_files(av, 1) || !valid_arg_commands(av, 2)
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
