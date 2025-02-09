#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int		in;
	int		out;
	char	*grep_args[] = {"grep", "ba", NULL};

	// open input and output files (assuming both files exist)
	in = open("in", O_RDONLY);
	if (in == -1) {
		perror("Open in");
		return (1);
	}
	out = open("out", O_WRONLY);
	if (out == -1) {
		close(in);
		perror("Open out");
		return (1);
	}

	// redirect stdin to input file
	// redirect stdout to output file
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);

	// close unused file descriptors
	close(in);
	close(out);

	// execute grep
	execve("/bin/grep", grep_args, env);
	// perror("execve");
}
