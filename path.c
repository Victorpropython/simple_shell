#include "shell.h"
/**
 * *search_path - to get the path
 * @command: used as a char pointer variable
 *
 * Return: to return path
*/

char *search_path(char *command)
{
	char *path = getenv("PATH");
	char *tok = my_strtok(path, ":");
	char *f_path = malloc(stnrlen(tok) + stnrlen(command) + 2);

	while (!tok)
	{
		if (f_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		our_strcpy(f_path, tok);
		our_strcat(f_path, "/");
		our_strcat(f_path, command);

		if (access(f_path, X_OK) == 0)
		{
			return (f_path);
		}
		free(f_path);
		tok = my_strtok(NULL, ":");
	}
	return (NULL);
}

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
/********************* To tokenise path ***********************/
/**
 * PATH - To tokenise string into substring
 * @envVar: Token pointer
 * @delim: Array for characters
 *
 * Return: Array tokenised substring
 */
char **toks_PATH(char *envVar, char *delim)
{
	char **tok = NULL;
	ssize_t size_substring;
	char envVar2[1024];
	int j = 0;

	our_strcpy(envVar2, envVar);
	size_substring = num_toks(envVar2, delim);
	tok = malloc(sizeof(char *) * size_substring);
	if (tok == NULL)
	{
		perror("Malloc unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	tok = tokenise_line(envVar, delim, size_substring);
	while (tok[j])
	{
		tok[j] = tok[j + 1];
		j++;
	}
	return (tok);
}

/***************************** _Getenvirons *************************/
/**
 * _getenvirons - A function that gets environment path
 * @nam: Environment to get the path
 *
 * Return: A pointer to new environment variable.
 */
char *_getenvirons(const char *nam)
{
	int size, j = 0;

	if (nam == NULL)
	{
		return (NULL);
	}
	size = stnrlen(nam);
	while (__environ[j] != NULL)
	{
		if (our_strncmp(nam, __environ[j], size) == 0)
		{
			break;
			j++;
		}
	}
	return (__environ[j]);
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
	our_strcpy(tmp, dir);
	our_strcat(tmp, alpha);
	our_strcat(tmp, argv[0]);
	return (tmp);
}
