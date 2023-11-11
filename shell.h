#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define INPUT 1024
#define ARGS_COUNT 20


void my_prompt();
int my_strlen(const char *c);
void my_print(const char *input);
void getargs(char *input, size_t size);
void exec_cmd(char *command);

/*
char *my_strdup(char *arg);
void exec(const char *argv[]);*/





#endif
