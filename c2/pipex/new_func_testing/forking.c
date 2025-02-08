#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

// fork() + wait()
/*int	main()
{
	int	id = fork();
	int	n;

	if (id == 0)
	{
		n = 1;
		// printf("child proc\n");
	}
	else
	{
		n = 6;
		wait();
		// printf("parent proc\n");
	}
	
	int	i;
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
	return (0);
}*/

// process IDs
/*int	main()
{
	int	id = fork();
	if (id == 0)
		sleep(1);
	printf("Current ID: %d, Parent ID: %d\n\n",
		getpid(), getppid());
	int	wait_res = wait(NULL);
	if (wait_res == -1)
		printf("No Children to wait for\n");
	else
		printf("%d finished execution\n", wait_res);
}*/


// Calling fork multiple times
/*int	main()
{
	int	id1 = fork();
	int	id2 = fork();

	if (id1 == 0)
	{
		if (id2 == 0)
			printf("We are process y\n");
		else
			printf("We are process x\n");
	}
	else
	{
		if (id2 == 0)
			printf("We are process z\n");
		else
			printf("We are the parent process\n");
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("waiting for a child to finish\n");

}*/


// Communication between processes (using pipe())
/*int	main()
{
	int	fd[2];
	// fd[0] - read
	// fd[1] - write
	if (pipe(fd) == -1) {
		printf("Error occurred when opening the pipe\n");
		return (1);
	}
	int	id = fork();
	if (id == -1) {
		printf("Error occurred with fork()");
		return (4);
	}
	if (id == 0)
	{
		close(fd[0]);
		int	x;
		printf("Child process here!\n=> Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1) {
			printf("Error occurred when writing to the pipe\n");
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int	y;
		if (read(fd[0], &y, sizeof(int)) == -1) {
			printf("Error occurred when reading from the pipe\n");
			return (3);
		}
		close(fd[0]);
		printf("--\nParent process here!\n=> got %d from child process.\n", y);
	}
	return (0);
}*/

