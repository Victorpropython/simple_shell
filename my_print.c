#include "shell.h"
/**
 * my-print - To print to command line
 * @input: char pointer to hold string
 *
 * Return: Always 0;
 */
void my_print(const char *input)
{
	write(STDOUT_FILENO, input, my_strlen(input));
}
