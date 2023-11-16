#include "shell.h"
/************************ for string duplicateion *************************/
/**
 * _strdup - dupplicates string
 * @org: pointer to string to be duplicated
 * Return: pointer to duplicated string
 */

char *_strdup(char *org)
{
	int first_size;
	static char *cpy;
	char *dup_offset;

	/* Allocate memory for duplicate */
	first_size = strlen(org);
	cpy = malloc(sizeof(char) * (first_size + 1));
	if (cpy == NULL)
		return ((char *)NULL);

	/* Copy string */
	dup_offset = cpy;
	while (*org)
	{
		*dup_offset = *org;
		dup_offset++;
		org++;
	}
	*dup_offset = '\0';

	return (cpy);
}
