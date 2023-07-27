#include "shell.h"
/**
* remove_comments - function replaces first instance of '#' with '\0'
* @buf: address of the string to modify
* Return: Always 0;
*/

void remove_comments(char *buf) {
    int i = 0;

    while (buf[i] != '\0') {
        if (buf[i] == '#' && (!i || buf[i - 1] == ' ')) {
            buf[i] = '\0';
            break;
        }
        i++;
    }
}

/**
* print_error - prints an error message
* @info: the parameter & return info struct
* @estr: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}
/**
* print_d - function prints a decimal (integer) number (base 10)
* @input: the input
* @fd: the filedescriptor to write to
* Return: number of characters printed
*/
int print_d(int input, int fd) {
    int (*__putchar)(char) = _putchar;
    int count = 0;
    unsigned int _abs_, current;
    unsigned int i; /* Change 'int i' to 'unsigned int i' */

    switch (fd) {
        case STDERR_FILENO:
            __putchar = _eputchar;
            break;
        default:
            break;
    }

    switch (input < 0) {
        case 1:
            _abs_ = -input;
            __putchar('-');
            count++;
            break;
        default:
            _abs_ = input;
            break;
    }

    current = _abs_;

    if (current == 0) {
        __putchar('0');
        return 1;
    }

    for (i = 1000000000; i >= 1; i /= 10) {
        switch (current >= i) {
            case 1:
                __putchar('0' + current / i);
                count++;
                break;
            default:
                break;
        }
        current %= i;
    }

    return (count);
}

/**
* _erratoi - changes a string to an integer
* @r: string to be changed
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
#include <limits.h>

int _erratoi(char *r) {
    int i = 0;
    unsigned long int result = 0;
    int negative = 0;

    if (*r == '-') {
        negative = 1;
        r++; /* Move past the negative sign */
    } else if (*r == '+') {
        r++; /* Move past the positive sign */
    }

    for (i = 0; r[i] != '\0'; i++) {
        if (r[i] >= '0' && r[i] <= '9') {
            result = result * 10 + (r[i] - '0');
            if (result > INT_MAX) {
                if (negative)
                    return INT_MIN;
                return INT_MAX;
            }
        } else {
            return -1; /* Invalid character encountered */
        }
    }

    return negative ? -result : result;
}
/**
* convert_number - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
* Return: string
*/
char *convert_number(long int num, int base, int flags) {
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    switch (!(flags & CONVERT_UNSIGNED) && num < 0) {
        case 1:
            n = -num;
            sign = '-';
            break;
        default:
            break;
    }

    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    while (n != 0) {
        *--ptr = array[n % base];
        n /= base;
    }

    switch (sign) {
        case '-':
            *--ptr = sign;
            break;
        default:
            break;
    }

    return ptr;
}
