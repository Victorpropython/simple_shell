#include "shell.h"
/************************ OUR_PUTCHAR ******************************/

/**
 * our_putchar - our putchar
 * @h: used as variable
 * Return: Always 0.
 */
void our_putchar(va_list h)
{
	char b;

	b = va_arg(h, int);
	write(1, &b, 1);
}

/********************* for print output *****************/

/**
 * my_print - To print to command line
 * @input: char pointer to hold string
 *
 * Return: Always 0;
 */
void my_print(const char *input)
{
	write(STDOUT_FILENO, input, stnrlen(input));
}
