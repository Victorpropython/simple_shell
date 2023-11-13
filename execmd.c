#include "shell.h"
/**
 * execmd - To execute command
 * @argv: variable for cmd line vector
 *
 * Return: nothing
 */
void execmd(char **argv)
{
	pid_t pid = fork();
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(cmd, argv, NULL) == -1)
			{
				perror("Error");
			}
		}
		else
		{
			wait(NULL);
		}
	}
	
}

