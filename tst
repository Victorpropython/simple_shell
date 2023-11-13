nt main(void)//int ac, char **argv)
{
        char *full_command = NULL,*copy_command = NULL;
        int i = 0;
        size_t size, m = 0;
        ssize_t nums;
        char **argv;
        //char *buff = NULL, *buff_copy = NULL;
        char *token;
        int num_toks = 0;
        const char *delim = " \n";

        //(void)ac; (void)argv;
        //while(1)


                printf("$");
                nums = getline(&full_command, &m, stdin);

                copy_command = malloc(sizeof(char) * nums);

                if (copy_command == NULL)
                {
                        perror("tsh: memory allocation error");
                        return (-1);
                }
                strcpy(copy_command, full_command);

                if (nums == -1)
                {
                        printf("Exiting shell ...\n");
                        return (-1);
                }
                else
                {
                        token = strtok(full_command, delim);


                  num_toks++;
                        //argv = malloc(sizeof(ch

                /*
                buff_copy = malloc(sizeof(char) *nums);
                if (buff_copy == NULL)
                {
                        perror("tsh: memory allocation error");
                        return (-1);
                }
                strcpy(buff_copy, buff);

                token = strtok(buff, delim);

                while (token != NULL)
                {
                        num_toks++;
                        token = strtok(NULL, delim);
                }*/
                        argv = malloc(sizeof(char *) * num_toks);

                        token = strtok(copy_command, delim);

                        for (i = 0; token != NULL; i++)
                        {
                                argv[i] = malloc(sizeof(char) * strlen(token));
                                strcpy(argv[i], token);

                                token = strtok(NULL, delim);
                        }
                        argv[i] = NULL;

                        free(argv);
                        free(full_command);
                        free(copy_command);
        }
        /* To remove newline character*/
        //input[strcspn(input, "\n")] = '\0';

        return (0);
}
