#include "shell.h"
#include <errno.h>
/**
 * main - Entry point for shell
 * @argc: used for argument count
 * @argv: used for aegument array
 *
 * Return: success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *buff_copy = NULL;
	char *buff = NULL;
	char **arg = NULL;
	ssize_t nums;
	size_t m = 0;
	struct flags flag;
	int toks_num, exit_lop = 1, cunt = 0;

	if (argc < 1)
	{
		return (-1);
	}
	signal(SIGINT, ctrl_c);
	while (exit_lop)
	{
		cunt++;
		exit_lop = prompt();
		/*exit_lop = prompt();*/
		nums = getline(&buff, &m, stdin);

		if (nums == -1)
		{
			errno = 0;
			return (-1);
		}
		buff_copy = _strdup(buff);
		toks_num = num_toks(buff_copy, DELIM);
		arg = tokenise_line(buff, DELIM, toks_num);

		if (arg[0] != NULL)
		{
			exec_commd(arg, argv, cunt);
		}
	}
	if (nums < 0 && flag.interactive)
		write(STDERR_FILENO, "\n", 1);

	free(buff_copy);
	free_buff(arg);
	return (0);
}
