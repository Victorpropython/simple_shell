#include "shell.h"

/***************************PRINT INTEGER *********************/
/**
 * _print_int - To print integer
 * @h: used as variable
 *
 * Return: Always 0.
 */
void _print_int(va_list h)
{
        char buffer[65];
        int m;

        m = va_arg(h, int);
        numToString(m, DECIMAL, buffer);
        write(STDOUT_FILENO, &buffer, stnrlen(buffer));
}

/************************* OUR PRINTF ******************************/
/**
 * our_printf - to print output according to a format type
 * @format: input type
 *
 * Return: to return any int or nums of chars
 */
int our_printf(const char *format, ...)
{
        va_list h;
        int m, n, nums;
        ss_t strngspec[] = {
                {'i', _print_int},
                {'s', _print_str},
                {'c', our_putchar},
                {'d', _print_int}
        };
        if (format == NULL)
        {
                return (0);
        }
        m = n = nums = 0;
        va_start(h, format);
        while (format[m])
        {
                if (format[m] == '%')
                {
                        n = 0;
                        while (n < 4)
                        {
                                if (format[m + 1] == strngspec[n].ss &&
                                                format[m + 1] != '%')
                                {
                                        strngspec[n].f(h);
                                        m++;
                                }
                                n++;
                        }
                        m++;
                        our_putchar_c(format[m]);
                }
                else
                {
                        our_putchar_c(format[m]);
                }
                nums++;
                m++;
        }
        return (nums);
}

/*********************** to print a single character *********************/
/**
 * our_puts - prints a string followed by a new line
 * @str: pointer variable.
 */
void our_puts(char *str)
{
        for (; *str != '\0'; str++)
                putchar(*str);
}

/*****************************OUR_PUTCHAR_C *******************************/
/**
 * our_putchar_c - used as a putchar
 * @c: used as variable
 * Return: Nothing
 */
void our_putchar_c(char c)
{
        write(1, &c, 1);
}

/**
 * _print_str - to print string
 * @h: used as variable
 *
 * Return: Always 0.
 */
void _print_str(va_list h)
{
        char *b;

        b = va_arg(h, char *);
        while (*b != '\0')
        {
                our_putchar_c(*b++);
        }
}

/************************ OUR_PUTCHAR ******************************/

/**
 * our_putchar - our putchar
 * @h: used as variable
 * Return: Always 0.
 */
void our_putchar(va_list h)
{
        char b;

        b = va_arg(h, int);
        write(1, &b, 1);
}

/********************* for print output *****************/

/**
 * my-print - To print to command line
 * @input: char pointer to hold string
 *
 * Return: Always 0;
 */
void my_print(const char *input)
{
        write(STDOUT_FILENO, input, stnrlen(input));
}
