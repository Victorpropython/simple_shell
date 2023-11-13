#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdarg.h>


#define INPUT 1024
#define ARGS_COUNT 20

#define DELIM " \n\t\a\r:"

extern char ** __environ;

void execmd(char **argv);
void my_prompt();
int my_strlen(const char *c);
void my_print(const char *input);
void getargs(char *input, size_t size);
void exec_cmd(char *command);

/************ For tokenization ***************/
char **tokenise_line(char *buffer, char *delim, int toks_num);
int num_toks(char *buffer, char *delim);

/********* To order path *************/
char *order_dir(char **ord);
/*
char *my_strdup(char *arg);
void exec(const char *argv[]);*/





#endif
