#include "shell.h"
/********************** to exec the shell ********************/
/**
 * exec - To execute a process
 *  
 * Return: to execute a program
 */
void exec(void)
{
	char **argv;
	pid_t pid = fork();
	int status;

	
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("exec");
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

