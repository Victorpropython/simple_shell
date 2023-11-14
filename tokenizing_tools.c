#include "shell.h"

/**
 * order_dir - used to searchfor directory path
 * @ord: the vairiable argument (pointer to pointer)
 *
 * Return: Always 0 success.
 */
/*
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
*/
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

/******************************** The NUMBER TOKENIZATION ****************/
/**
 * num_toks -Use in finding the number of substring in string
 * @buffer: Pointer used for string tokenization
 * @delim: This is the delimiter variable in tokenization
 * Return: To return the number of substrings found
 * 
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

/******************* For strtok ***************/

char *my_strtok(char *str, const char *delim)
{
	static char *lastoken = NULL;
	char *startoken;
	char *endtoken;

	if (str != NULL)
	{
		lastoken = str;
	}
	else
	{
		if (lastoken == NULL)
		{
			return (NULL);
		}
	}
	startoken = lastoken;

	while (*lastoken != '\0' && strchr(delim, *lastoken) != NULL)
	{
		lastoken++;
	}

	if (*lastoken == '\0')
	{
		lastoken = NULL;
		return (NULL);
	}
	endtoken = lastoken;

	while (*lastoken != '\0' && strchr(delim, *lastoken) == NULL)
	{
		lastoken++;
	}

	if (*lastoken != '\0')
	{
		*lastoken = '\0';
		lastoken++;
	}
	return (startoken);
}
