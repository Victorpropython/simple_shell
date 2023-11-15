#include "shell.h"
/**
 * main - The entry point
 * @ac: argument count
 * @argv: argument vector
 * Return: Always 0;
 */
int main(int ac __attribute__((unused)), char **argv)
{
	int count = 0;

	/*signal(SIGINT, ctrl_c);*/
	while (1)
	{
		count++;
		our_printf("$");
		process_input(count, argv);
	}
	return (0);
}
/***************** continuation *********/
/**
 * process_input - to process the argument inputs
 * @argv: argument vector
 * @ac: argument count
 */

void process_input(int ac __attribute__((unused)), char **argv)
{
	ssize_t nums;
	size_t m;
	const char *delim = " \n";
	char *buff = NULL, *buff_copy = NULL, *token, **arg;
	int toknum, i, nums_toks = 0, count = 0;

	nums = getline(&buff, &m, stdin);
	if (nums == -1)
	{
		our_printf("Exiting shell ...\n");
	}
	buff_copy = malloc(sizeof(char) * nums);
	if (buff_copy == NULL)
	{
		perror("tsh: memory allocation error");
		return;
	}
	our_strcpy(buff_copy, buff);
	token = my_strtok(buff, delim);
	while (token != NULL)
	{
		nums_toks++;
		token = my_strtok(NULL, delim);
	}
	nums_toks++;
	argv = malloc(sizeof(char *) * nums_toks);
	token = my_strtok(buff_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * stnrlen(token));
		our_strcpy(argv[i], token);
		token = my_strtok(NULL, delim);
	}
	toknum = num_toks(buff_copy, DELIM);
	arg = tokenise_line(buff, DELIM, toknum);
	argv[i] = NULL;
	if (arg[0] != NULL)
		exec_commd(arg, argv, count);
	free(buff_copy);
	free(buff);
}
