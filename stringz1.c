#include "shell.h"
/*************************** for stnrcpy ************************/
/**
 * our_strcpy - copies the string pointed to src to dest including \0
 * @src: pointer to source string
 * @dest: destination buffer
 * Return: pointer to dest
 */

char *our_strcpy(char *dest, char *src)
{
	char *copy = dest;

	while (*src)
		*dest++ = *src++;
	return (copy);
}

/*********************** UNSGNEDNUMTOSTRING ***************************/
/**
 * unsgnednumToString - Use to change a number to string
 * @num: For unsigned number
 * @target: start of the number
 * @buff: for buffer pointer
 */
void unsgnednumToString(uint64_t num, int target, char *buff)
{
	char fil[65];
	int mor, m = 0, n = 0;

	if (num == 0)
	{
		*buff++ = '0';
		*buff = '\0';
		return;
	}
	while (num)
	{
		mor = num % target;
		if (mor >= 10)
		{
			fil[m++] = 'a' + (mor - 10);
		}
		else
		{
			fil[m++] = '0' + mor;
		}
		num /= target;
	}
	for (n = m - 1; n >= 0; n--)
	{
		*buff++ = fil[n];
	}
	*buff = '\0';
}
/************************** Convert Number To String **********************/
/**
 * numToString - To convert numbers to string
 * @num: for unsigned number
 * @target: base number
 * @buff: pointer variable
 *
 * Return: Always 0.
 */
void numToString(int64_t num, int target, char *buff)
{
	if (num < 0)
	{
		buff[0] = '-';
		num *= -1;
	}
	unsgnednumToString(num, target, buff);
}


/*********************** for string compare 2 ******************************/
/**
 * our__strcmp - A function that works exactly like strcmp
 * @str1: First string
 * @str2: Second string
 * Return: int
 */

int our__strcmp(char *str1, char *str2)
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

