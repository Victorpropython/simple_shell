#include "shell.h"
/************************ for string duplicateion *************************/
/**
 * *our_strdup - dupplicates string
 * @org: pointer to string to be duplicated
 * Return: pointer to duplicated string
 */

char *our_strdup(char *org)
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

/***************************** for string character ************************/
/**
 * *our_strchr - function that finds the character we are seaching
 * @str: the string we are using to parse for the character
 * @b: the character we are searching
 * Return: returns the character on success and NULL if it fails
 */
char *our_strchr(char *str, int b)
{
	char *ptr;

	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == b)
			return (ptr);
	}
	return (NULL);
}

/************************ for string concatenation **********************/

/**
 * *our_strcat - appends string to destination string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: dest string
 */

char *our_strcat(char *dest, char *src)
{
	int num1;
	int num2;
	int j;

	num1 = stnrlen(dest);
	num2 = stnrlen(src);

	for (j = 0; j <= num2; j++)
		dest[num1 + j] = src[j];

	return (dest);
}

/*********************** for string lenght **************************/
/**
 * stnrlen - returns the length of a string
 * @u: Argument is a string
 *
 * Return: length of the string
 */

int stnrlen(const char *u)
{
	int j;
	int size = 0;

	for (j = 0; u[j] != '\0'; j++)
	{
		size++;
	}
	return (size);
}

/*************************** for string compare ***********************/
/**
 * our_strncmp - A function that works exactly like strcmp
 * @str1: First string
 * @str2: Second string
 * @m: How many bytes to comapare atmost
 * Return: int
 */

int our_strncmp(const char *str1, const char *str2, size_t m)
{
	int indicate;

	indicate = strncmp(str1, str2, m);
	return (indicate);
}
