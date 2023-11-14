#include "shell.h"
/**
 * main: The entry point
 * 
 * Return: Always 0;
 */
int main(int ac, char **argv)
{

	int i = 0;
	size_t  m = 0;
	ssize_t nums;
	char *buff = NULL, *buff_copy = NULL;
	char *token;
	int nums_toks = 0;
	const char *delim = " \n";
	
	(void)ac; /*(void)argv;*/
	while(1)
	{

		our_printf("$");
		nums = getline(&buff, &m, stdin);

		
		if (nums == -1)
		{
			our_printf("Exiting shell ...\n");
			return (-1);
		}
						
		buff_copy = malloc(sizeof(char) *nums);
		if (buff_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		our_strcpy(buff_copy, buff);

		token = my_strtok(buff, delim);

		while (token != NULL)
		{
			nums_toks++;
			token = my_strtok(NULL, delim);
		}
		nums_toks++;
		argv = malloc(sizeof(char *) * nums_toks);

		token = my_strtok(buff_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * stnrlen(token));
			our_strcpy(argv[i], token);
			token = my_strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
		
	}
	/* To remove newline character
	//input[strcspn(input, "\n")] = '\0';*/

	free(buff_copy);
	free(buff);
	return (0);
}

