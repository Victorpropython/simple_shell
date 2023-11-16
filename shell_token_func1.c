#include "shell.h"

/**
 * order_dir - used to searchfor directory path
 * @ord: the vairiable argument (pointer to pointer)
 *
 * Return: Always 0 success.
 */

char *order_dir(char **ord)
{
	int j = 0;
	size_t input = 0;
	struct stat stt;
	char *orderPath = NULL;
	char *environsPath = NULL;
	char *cwd = NULL;
	char **pathToks = NULL;

	environsPath = getenv("PATH");
	pathToks = toks_PATH(environsPath, DELIM);
	cwd = getcwd(NULL, input);

	if (cwd == NULL)
	{
		return (NULL);
	}
	while (pathToks[j] != NULL)
	{
		chdir(pathToks[j]);
		if (stat(ord[0], &stt) == 0)
		{
			orderPath = add_to_dir(pathToks[j], ord, "/");
			break;
		}
		j++;
	}
	chdir(cwd);
	free(pathToks);
	pathToks = NULL;
	return (orderPath);
}

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

	toks = strtok(buffer, delim);
	toks_num++;

	while (toks != NULL)
	{
		toks = strtok(NULL, delim);
		toks_num++;
	}
	return (toks_num);
}
