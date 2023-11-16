#include "shell.h"
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
/************************ for string concatenation **********************/

/**
 * _strcat - appends string to destination string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: dest string
 */

char *_strcat(char *dest, char *src)
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
/***************************** for string character ************************/
/**
 * _strchr - function that finds the character we are seaching
 * @str: the string we are using to parse for the character
 * @b: the character we are searching
 * Return: returns the character on success and NULL if it fails
 */
char *_strchr(char *str, int b)
{
	char *ptr;

	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == b)
			return (ptr);
	}
	return (NULL);
}
/*********************** to print a single character *********************/
/**
 * our_puts - prints a string followed by a new line
 * @str: pointer variable.
 */
void our_puts(char *str)
{
	for (; *str != '\0'; str++)
		putchar(*str);
}
