#include "shell.h"
/**
 * main: The entry point
 * 
 * Return: Always 0;
 */
int main()
{
	char input[INPUT];
	size_t size;
	while(1)
	{
		my_prompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		getargs(input,size);
		exec_cmd(input);

	}
	/* To remove newline character*/
	input[strcspn(input, "\n")] = '\0';
	return (0);
}

