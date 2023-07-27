#include "shell.h"
/**
 * _eputs - outputs a string input
 * @str: the string to print
 * Return: Nothing
 */
void _eputs(char *str)
{
    int i = 0;
    
    if (!str)
        return;
    
    do
    {
        _eputchar(str[i]);
        i++;
    } while (str[i] != '\0');
}
/**
 * _eputchar - writes the character d to stderr
 * @d: printing the character
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char d)
{
    static int i = 0;
    static char buf[WRITE_BUF_SIZE];

    for (; i < WRITE_BUF_SIZE; i++)
    {
        if (d == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
            write(2, buf, i);
            i = 0;
        }
        if (d != BUF_FLUSH)
        {
            buf[i] = d;
            i++;
        }
        break;
    }
    
    return (1);
}
/**
 * _putfd - writes the character d to the specified fd
 * @d: The character to print
 * @fd: The file descriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char d, int fd)
{
    static int i = 0;
    static char buf[WRITE_BUF_SIZE];

    int flushBuffer = (d == BUF_FLUSH || i >= WRITE_BUF_SIZE);

    while (!flushBuffer)
    {
        buf[i++] = d;
        flushBuffer = (i >= WRITE_BUF_SIZE);
        break;
    }

    if (flushBuffer)
    {
        write(fd, buf, i);
        i = 0;
    }

    return (1);
}
/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 * Return: the number of characters put
 */
int _putsfd(char *str, int fd)
{
    int i;

    if (!str)
        return (0);

    for (i = 0; str[i] != '\0'; i++)
        _putfd(str[i], fd);

    return (i);
}

