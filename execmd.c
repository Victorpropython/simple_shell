#include "shell.h"

/******************** EXEC_COMMD ************************************/
/**
 * exec_commd - Function use to execute command
 * @arg: Anarray of command
 * @num: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0.
 */
void exec_commd(char **arg, char **argv, int num)
{
	pid_t pid;
	char *comd = NULL;
	int chr = '/', stat;

	if (to_exec_commands(arg) == 0)
	{
		return;
	}
	if (our_strchr(arg[0], chr) == NULL)
	{
		comd = add_to_dir("/bin", arg, "/");
	}
	else
	{
		comd = arg[0];
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Unable to create child process\n");
		return;
	}
	else if (pid == 0)
	{
		if (execve(comd, arg, __environ) == -1)
		{
			our_printf("%s: %!: %s: not found \n", argv[0], num, arg[0]);
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, &stat, WUNTRACED);
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
		if (our__strcmp(builtin[j].command, argv[0]) == 0)
		{
			builtin[j].func(argv);
			return (0);
		}
	}
	return (-1);
}
