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
/*********************** UNSGNEDNUMTOSTRING ***************************/
/**
 * unsgnednumToString - Use to change a number to string
 * @num: For unsigned number
 * @target: start of the number
 * @buff: for buffer pointer
 */
void unsgnednumToString(uint64_t num, int target, char *buff)
{
	char fil[65];
	int mor, m = 0, n = 0;

	if (num == 0)
	{
		*buff++ = '0';
		*buff = '\0';
		return;
	}
	while (num)
	{
		mor = num % target;
		if (mor >= 10)
		{
			fil[m++] = 'a' + (mor - 10);
		}
		else
		{
			fil[m++] = '0' + mor;
		}
		num /= target;
	}
	for (n = m - 1; n >= 0; n--)
	{
		*buff++ = fil[n];
	}
	*buff = '\0';
}
/************************** Convert Number To String **********************/
/**
 * numToString - To convert numbers to string
 * @num: for unsigned number
 * @target: base number
 * @buff: pointer variable
 *
 * Return: Always 0.
 */
void numToString(int64_t num, int target, char *buff)
{
	if (num < 0)
	{
		buff[0] = '-';
		num *= -1;
	}
	unsgnednumToString(num, target, buff);
}
