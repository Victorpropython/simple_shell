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
#include <signal.h>
#include <limits.h>
#include <dirent.h>
#include <sys/stat.h>

#define INPUT 1024
#define ARGS_COUNT 20

#define DECIMAL 10
#define HEX 16

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


extern char** __environ;

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




/************ For tokenization ***************/
int num_toks(char *buffer, char *delim);
unsigned int is_delim(char c, const char *delim);
char *my_strtok(char *srcString, const char *delim);

 


/********* To order path *************/
char *order_dir(char **ord);
char *search_path(char *command);

/***************** for directory path ********/
char *_getenvirons(const char *nam);
char *add_to_dir(char *dir, char **argv, char *alpha);
char **toks_PATH(char *envVar, char *delim);
char **tokenise_line(char *buffer, char *delim, int toks_num);



#endif
