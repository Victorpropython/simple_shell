#include "shell.h"
/**********************_prompt *******************************/
/**
 * prompt - this is used to print the $ sign and
 * signal for input by a user
 *Return: Nothing
 */
int prompt(void)
{
	struct victor flag;

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
	{
		flag.interactive = 1;
		write(STDOUT_FILENO, "$ ", 2);
	}
	return (1);
}

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
	if (_strchr(arg[0], chr) == NULL)
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
			our_printf("%s: %!: %s: not found\n", argv[0], num, arg[0]);
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, &stat, WUNTRACED);
}

/****************** adding to directory ********************************/
/**
 * add_to_dir - To add '/' and command name to the end of a dir
 * @dir: command directory for adding character and command
 * @alpha: character to add
 * @argv: Array ofcammand passed
 *
 * Return: pionts to the new string
 */
char *add_to_dir(char *dir, char **argv, char *alpha)
{
	char *tmp = NULL;
	int buf_num;

	buf_num = (stnrlen(dir) + stnrlen(argv[0] + 2));
	tmp = malloc(sizeof(char) * buf_num);
	if (!tmp)
	{
		return (argv[0]);
	}
	if (dir == NULL)
	{
		return (argv[0]);
	}
	_strcpy(tmp, dir);
	_strcat(tmp, alpha);
	_strcat(tmp, argv[0]);
	return (tmp);
}
