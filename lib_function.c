#include "shell.h"
/*************************** for stnrcpy ************************/
/**
 * _strcpy - copies the string pointed to src to dest including \0
 * @src: pointer to source string
 * @dest: destination buffer
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *copy = dest;

	while (*src)
		*dest++ = *src++;
	return (copy);
}

/*************************** for string compare ***********************/
/**
 * _strncmp - A function that works exactly like strcmp
 * @str1: First string
 * @str2: Second string
 * @m: How many bytes to comapare atmost
 * Return: int
 */

int _strncmp(const char *str1, const char *str2, size_t m)
{
	int indicate;

	indicate = strncmp(str1, str2, m);
	return (indicate);
}
/*********************** for string compare 2 ******************************/
/**
 * __strcmp - A function that works exactly like strcmp
 * @str1: First string
 * @str2: Second string
 * Return: int
 */

int __strcmp(char *str1, char *str2)
{

	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
