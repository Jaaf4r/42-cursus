#include "pipex.h"

void	free_all(char **ss)
{
	int	i;

	if (!ss)
		return ;
	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
}
