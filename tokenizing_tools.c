#include "shell.h"
/************ for strtok ********************/
/**
 * is_delim - used to specify delimeter variable
 * @c: argument for variable
 * @delim: delimeter
 * Return: to return 0
 */

unsigned int is_delim(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}

/********** for string token ****************/
/**
 * my_strtok - function for tokenization
 * @srcString: To indicate the first string
 * @delim: Used for delim variable
 * Return: to return srcString
 */

char *my_strtok(char *srcString, const char *delim)
{
	static char *backup_string;
	char *ret;

	if (!srcString)
	{
		return (NULL);
	}

	while (1)
	{
		if (is_delim(*srcString, delim))
		{
			srcString++;
			continue;
		}
		if (*srcString == '\0')
		{
			return (NULL);
		}
		break;
	}
	ret = srcString;
	while (1)
	{
		if (*srcString == '\0')
		{
			backup_string = srcString;
			return (ret);
		}
		if (is_delim(*srcString, delim))
		{
			*srcString = '\0';
			backup_string = srcString + 1;
			return (ret);
		}
		srcString++;
	}
}

