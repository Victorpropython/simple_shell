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
#include <stdint.h>

#define INPUT 1024
#define ARGS_COUNT 20

#define DECIMAL 10

#define DELIM " \n\t\a\r:"

/**
 * struct strngspecc - structure for format specifier
 * @ss: used as specifier
 * @f: a pointer to function
 * Descriptor: used for printf
 */


typedef struct strngspec
{
	char ss;
	void (*f)();
} ss_t;


extern char ** __environ;

void execmd(char **argv);
void my_prompt();

/********** for all printing *********/
void _print_int(va_list h);
int our_printf(const char *format, ...);
void our_puts(char *str);
void _print_str(va_list h);
void our_putchar_c(char c);
void our_putchar(va_list h);
void our_print(const char *input);



/******** for all strings tools ***************/

char *our_strcpy(char *dest, char *src);
int our_strncmp(const char *str1, const char *str2, size_t m);
int our__strcmp(char *str1, char *str2);
char *our_strcat(char *dest, char *src);
void numToString(int64_t num, int target, char *buff);
void unsgnednumToString(uint64_t num, int target, char *buff);
int stnrlen(const char *u);
char *our_strchr(char *str, int b);
char *our_strdup(char *org);

/*int my_strlen(const char *c);
void my_print(const char *input);
void getargs(char *input, size_t size);
void exec_cmd(char *command);

*/

/************ For tokenization ***************/
char **tokenise_line(char *buffer, char *delim, int toks_num);
int num_toks(char *buffer, char *delim);
/*char *my_strtok(char *str, const char *delim);*/
unsigned int is_delim(char c, const char *delim);
char *my_strtok(char *srcString, const char *delim);

 


/********* To order path *************/
char *order_dir(char **ord);
/*
char *my_strdup(char *arg);
void exec(const char *argv[]);*/





#endif
