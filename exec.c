#include "shell.h"
/**
 * exec_cmd - To execute command line args
 * @command: pointer to args
 *
 * Return: Always (0)
 */
void exec_cmd(char *command)
{
	pid_t pid = fork();
	char *argv[ARGS_COUNT];
	int argc;
	char *token;
	char *delim = " ";
	int status;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		argv[ARGS_COUNT + 2];
		argc = 0;
		argv[argc++] = command;
		token = strtok(NULL, delim);

		while (token != NULL && argc < ARGS_COUNT)
		{
			argv[argc++] = token;
			token = strtok(NULL, delim);
		}
		argv[argc] = NULL;
		if (execve(command, argv,NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
		{
			my_print("command not found ");
		}
	}

}
