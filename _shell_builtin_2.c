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

/***************************** Execution of Builtin Commands *****************/

/**
 * to_exec_commands - Functions toexecute built in commands
 * @argv: the argument array passed
 * our_builtin: this is the struct that relates to the functions
 *
 * Return: returns 0 on successor -1 on failure
 */

int to_exec_commands(char **argv)
{
	int build_size, j;

	builtins builtin[] = {
		{"exit", to_exit},
		{"_cd", for_cd},
		{"environs", print_environs},
	};
	build_size = sizeof(builtin) / sizeof(builtins);
	for (j = 0; j < build_size; j++)
	{
		if (__strcmp(builtin[j].command, argv[0]) == 0)
		{
			builtin[j].func(argv);
			return (0);
		}
	}
	return (-1);
}
