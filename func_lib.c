#include "shell.h"
/************************* For string Lenght ************************/
/**
 * my-strlen - to return the length of a string
 * @c: Argument of a string
 *
 * Return: Length of the string
 */
int my_strlen(const char *c)
{
	int i;
	int size = 0;

	for (i = 0; c[i] != '\0'; i++)
	{
		size++;
	}
	return (size);
}


/********************************* for String Duplication ********************/
/**
 * my_strdup - To duplicate string
 * @arg: pointer to string to be duplicated
 *
 * Return: return pointer to duplicated string
 */
char *my_strdup(char *arg)
{
	int size1;
	static char *copy;
	char *dup;

	/* Allocate memory for duplication*/
	size1 = my_strlen(arg);
	copy = malloc(sizeof(char) * (size1 + 1));

	if (copy == NULL)
	{
		return ((char *) NULL);
	}

	/* copy string */
	dup = copy;
	while (*arg)
	{
		*dup = *arg;
		dup++;
		arg++;
	}
	dup = '\0';

	return (copy);
}


