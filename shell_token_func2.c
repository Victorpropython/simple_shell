#include "shell.h"

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
		print("\n$", STDIN_FILENO);
	}
}

/****************************** MY PRINT ****************************/

/**
 * print - function used for printing file output
 * @vic: used as variable
 * @df: descriptor for file
 *
 * Return: Always 0 (success) , -1(failure)
 */
int print(char *vic, int df)
{
	return (write(df, vic, stnrlen(vic)));
}

/*************************** TOKENIZATION OF LINE**************************/
/**
 * tokenise_line - Function used in breaking string into substring
 * @buffer: string pointer for tokenisation
 * @delim: used as delimeter
 * @toks_num: number of string token broken into substring
 *
 * Return: pointer String arrays of substring
 */
char **tokenise_line(char *buffer, char *delim, int toks_num)
{
	char *toks = NULL;
	char **argv = NULL;
	int i = 0;

	argv = malloc(sizeof(char *) * toks_num);

	if (argv == NULL)
	{
		perror("No space given\n");
		exit(EXIT_FAILURE);
	}
	toks = strtok(buffer, delim);
	while (toks)
	{
		argv[i] = toks;
		i++;
		toks = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
