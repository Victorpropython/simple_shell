#include "shell.h"
/************************ for string duplicateion *************************/
/**
 * _strdup - dupplicates string
 * @org: pointer to string to be duplicated
 * Return: pointer to duplicated string
 */

char *our_strdup(char *org)
{
        int first_size;
        static char *cpy;
        char *dup_offset;

        /* Allocate memory for duplicate */
        first_size = strlen(org);
        cpy = malloc(sizeof(char) * (first_size + 1));
        if (cpy == NULL)
                return ((char *)NULL);

        /* Copy string */
        dup_offset = cpy;
        while (*org)
        {
                *dup_offset = *org;
                dup_offset++;
                org++;
        }
        *dup_offset = '\0';

        return (cpy);
}

/***************************** for string character ************************/
/**
 * _strchr - function that finds the character we are seaching
 * @str: the string we are using to parse for the character
 * @b: the character we are searching
 * Return: returns the character on success and NULL if it fails
 */
char *our_strchr(char *str, int b)
{
        char *ptr;

        for (ptr = str; *ptr; ptr++)
        {
                if (*ptr == b)
                        return (ptr);
        }
        return (NULL);
}

/************************ for string concatenation **********************/

/**
 * _strcat - appends string to destination string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: dest string
 */

char *our_strcat(char *dest, char *src)
{
        int num1;
        int num2;
        int j;

        num1 = stnrlen(dest);
        num2 = stnrlen(src);

        for (j = 0; j <= num2; j++)
                dest[num1 + j] = src[j];

        return (dest);
}

/*********************** for string lenght **************************/
/**
 * stnrlen - returns the length of a string
 * @u: Argument is a string
 *
 * Return: length of the string
 */

int stnrlen(const char *u)
{
        int j;
        int size = 0;

        for (j = 0; u[j] != '\0'; j++)
        {
                size++;
        }
        return (size);
}

/*************************** for string compare ***********************/
/**
 * _strncmp - A function that works exactly like strcmp
 * @str1: First string
 * @str2: Second string
 * @m: How many bytes to comapare atmost
 * Return: int
 */

int our_strncmp(const char *str1, const char *str2, size_t m)
{
        int indicate;

        indicate = strncmp(str1, str2, m);
        return (indicate);
}

/*************************** for stnrcpy ************************/
/**
 * _strcpy - copies the string pointed to src to dest including \0
 * @src: pointer to source string
 * @dest: destination buffer
 * Return: pointer to dest
 */

char *our_strcpy(char *dest, char *src)
{
        char *copy = dest;

        while (*src)
                *dest++ = *src++;
        return (copy);
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

/*********************** for string compare 2 ******************************/
/**
 * __strcmp - A function that works exactly like strcmp
 * @str1: First string
 * @str2: Second string
 * Return: int
 */

int our__strcmp(char *str1, char *str2)
{

        while (*str1 != '\0' && *str2 != '\0')
        {
                if (*str1 != *str2)
                {
                        return (*str1 - *str2);
                }
                str1++;
                str2++;
        }
        return (*str1 - *str2);
}

