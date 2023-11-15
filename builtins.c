#include "shell.h"
/**
 * to_exit - to exit the shell
 * @args: the command entered
 *
 * Return: returns nothing.
 */
void to_exit(char **args)
{
	free(args);
	exit(0);
}

/***************************** FOR CHANGE OF DIRECTORY ******************/
/**
 * for_cd - use for change of directory
 * @args: for argument variable
 */
void for_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("cd: Argument is missing\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("_cd\n");
		}
	}
}

/**
 * print_environs - to print out environment viriable
 * @args: command vector
 *
 * Return: Always 0.
 */
void print_environs(char **args __attribute__((unused)))
{
	int j = 0;

	if (__environ[j] != NULL)
	{
		our_printf("%s\n", __environ[j]);
		j++;
	}
}

/**
 * ctrl_c - Assingning ctrl + c as a kill signal
 * @signum: signum
 *
 * Return: Always 0.
 */
void ctrl_c(int signum)
{
	if (signum == SIGINT)
	{
		our_printf("\n$", STDIN_FILENO);
	}
}
