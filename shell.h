#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include <errno.h>

#define HEX 16
#define DECIMAL 10
#define UNUSED __attribute__((UNUSED))
#define UNSED
extern char **__environ;

#define DELIM " \n\t\a\r:"



/**
 * struct strngspec - structure for format specifier
 * @ss: Used to represent specifier
 * @f: a pointer to function
 * DEscriptor: Used for printf
 */
typedef struct strngspec
{
	char ss;
	void (*f)();
} ss_t;

/***** for builtin *******/

/**
 * struct builtins- structure for builtins
 * @command: member for struct
 * @func: pointer to a function
 * Descriptor: used for..
 */
typedef struct builtins
{
	char *command;
	void (*func)(char **);
} builtins;

/**
 * struct victor - use for interaction
 * @interactive: mode system
 * Describe: For interaction
 */
typedef struct flags
{
	bool interactive;
} flag;

/** for library functions ********/



/******** for shell builtins ***************/
void print_environs(char **args __attribute__((unused)));
void for_cd(char **args);
void to_exit(char **args);
int to_exec_commands(char **argv);

/********* for shell tools ********************/
void _print_int(va_list h);
int our_printf(const char *format, ...);
void unsgnednumToString(uint64_t num, int target, char *buff);
void numToString(int64_t num, int target, char *buff);
void _print_str(va_list h);
void our_putchar(va_list h);
void our_putchar_c(char c);
void free_buff(char **argv);

/****** for Library functions ******************/
char *_strcpy(char *dest, char *src);
int _strncmp(const char *str1, const char *str2, size_t m);
int __strcmp(char *str1, char *str2);
int stnrlen(const char *u);
char *_strcat(char *dest, char *src);
char *_strchr(char *str, int b);
void our_puts(char *str);
char *_strdup(char *org);

/************* for tokenization ******************/
char *order_dir(char **ord);
int num_toks(char *buffer, char *delim);
void ctrl_c(int signum);
int print(char *vic, int df);
char **tokenise_line(char *buffer, char *delim, int toks_num);

/************* for utility tools ********************/
int prompt(void);
void exec_commd(char **arg, char **argv, int num);
char *add_to_dir(char *dir, char **argv, char *alpha);
char *_getenvirons(const char *nam);
char **toks_PATH(char *envVar, char *delim);





#endif
