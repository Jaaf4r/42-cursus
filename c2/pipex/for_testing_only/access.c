#include "../pipex.h"

int	main()
{
	if (access("readfile", R_OK) == 0)
		printf("readfile is accessible in reading mode\n");
	if (access("writefile", W_OK) == 0)
		printf("writefile is accessible in writing mode\n");
	if (access("executefile", X_OK) == 0)
		printf("executefile is accessible in execution mode\n");
	if (access("rwfile", R_OK|W_OK) == 0)
		printf("rwfile is accessible in writing and reading mode\n");
}
