#include "shell.h"
/**
 * cmd_arg - For command line argument
 * @argc: argument count
 * @argv: argument vector
 *
 * REturn: to return the argc and argv
 */
int cmd_arg(void)
{
	char *cmd = NULL, *cmd_copy = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int argc = 0, j = 0;
	char **argv = NULL;

	if(getline(&cmd, &n, stdin) == -1)
	{
		return (-1);
	}
	cmd_copy = my_strdup(cmd);

	token = strtok(cmd, delim);

	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	argv = malloc(sizeof(char *) * argc);
	token = strtok(cmd_copy, delim);
	
	while (token)
	{
		argv[j] = token;
		token = strtok(NULL, delim);
		j++;
	}
	argv[j] = NULL;
	return (0);
}
