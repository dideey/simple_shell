#include "main.h"
/**
 *_putchar - a function that prints a single
 *		character to the stdout
 *@c: the character to be printed
 *Return: returns 1 on success and -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
