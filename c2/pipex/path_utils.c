#include "pipex.h"

char	**get_env_path(void)
{
	char	**paths;
	char	*tmp;

	tmp = getenv("PATH");
	if (!tmp)
        return (NULL);
	paths = ft_split(tmp, ':');
	return (paths);
}

char	*join_paths(char *cmd, char **env_path)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = 0;
	while (env_path[i])
	{
		tmp = ft_strjoin(env_path[i], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*find_command(char *cmd)
{
	char	*cmd_path;
	char	**env_path;

	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	env_path = get_env_path();
	if (!env_path)
		return (NULL);
	cmd_path = join_paths(cmd, env_path);
	if (!cmd_path)
		return (free_all(env_path), NULL);
	return (free_all(env_path), cmd_path);
}
