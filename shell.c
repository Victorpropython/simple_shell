#include "shell.h"
/**
 * main: The entry point
 * 
 * Return: Always 0;
 */
int main()
{
	char input[INPUT];
	while(1)
	{
		my_prompt();
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

	}
	return (0);
}

