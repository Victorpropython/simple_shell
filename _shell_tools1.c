#include "shell.h"
/**
 * _print_str - to print string
 * @h: used as variable
 *
 * Return: Always 0.
 */
void _print_str(va_list h)
{
	char *b;

	b = va_arg(h, char *);
	while (*b != '\0')
	{
		our_putchar_c(*b++);
	}
}
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
/*****************************OUR_PUTCHAR_C *******************************/
/**
 * our_putchar_c - used as a putchar
 * @c: used as variable
 * Return: Nothing
 */
void our_putchar_c(char c)
{
	write(1, &c, 1);
}
/************************** Used to free Buffer ****************************/
/**
 * free_buff -Used to free the buffer
 * @argv: array vector
 *
 * Return: Always 0.
 */
void free_buff(char **argv)
{
	int j = 0;

	while (argv[j])
	{
		free(argv[j]);
		j++;
	}
	free(argv);
}
