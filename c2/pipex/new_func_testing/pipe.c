#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	int	pipefd[2];
	int	pid;

	char	*cat_args[] = {"/usr/bin/cat", "in", NULL};
	char	*grep_args[] = {"/usr/bin/grep", "Btata", NULL};

	pipe(pipefd);

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	else if (pid == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);

		execve(grep_args[0], grep_args, env);
	}
	else
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);

		execve(cat_args[0], cat_args, env);
	}

	waitpid(pid, NULL, 0);
}
