#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define INPUT 1024

void my_prompt();
int my_strlen(const char *c);
void my_print(const char *input);
int cmd_arg(void);
char *my_strdup(char *arg);
void exec(void);





#endif
