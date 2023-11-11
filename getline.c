#include "shell.h"
/**
 * getline: To get the command line arguments
 * @input: Used as variable to hold command line
 * @size: used for argument size in bytes
 *
 * return: to retun nothing
 */
void getargs(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			my_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			my_print("Error Reading inputs");
			exit(EXIT_FAILURE);
		}
	}
}
