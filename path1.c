#include "shell.h"

/******************************** The NUMBER TOKENIZATION ****************/
/**
 * num_toks -Use in finding the number of substring in string
 * @buffer: Pointer used for string tokenization
 * @delim: This is the delimiter variable in tokenization
 * Return: To return the number of substrings found
 */
int num_toks(char *buffer, char *delim)
{
	int toks_num = 0;
	char *toks = NULL;

	toks = my_strtok(buffer, delim);
	toks_num++;
	while (toks != NULL)
	{
		toks = my_strtok(NULL, delim);
		toks_num++;
	}
	return (toks_num);
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
	toks = my_strtok(buffer, delim);
	while (toks)
	{
		argv[i] = toks;
		i++;
		toks = my_strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}
