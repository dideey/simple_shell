#include "shell.h"
#include <unistd.h>

/**
 * interactive - return 0 if non_interactive mode is on
 * confirms the initial mode thats on
 * @info: structure address
 *Return: true or false, 1 or 0.
 */

int interactive(info_t *info)
{
	if (isatty(STDIN_FILENO) && info != NULL && info->readfd <= 2)
	{
		return (1); /*true*/
	}
	else
	{
		return (0); /*false*/
	}

}

/**
 *_atoi - converts a string to an integer
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int signMultiplier = 1; /* sign*/
	unsigned int convertedValue = 0; /* the outcome result*/
	int digitFlag = 0; /*the resignated  flag*/

	while (*str != '\0' && digitFlag != 2)
	{
		if (*str == '-')
			signMultiplier *= -1;
		else if (*str >= '0' && *str <= '9')
		{
			digitFlag = 1;
			convertedValue = convertedValue * 10 + (*str - '0');
		}
		else if (digitFlag == 1)
			digitFlag = 2;

		str++;
	}

	return ((signMultiplier == -1) ? -convertedValue : convertedValue);
}
/**
 *is_letter - confirms is c is an alphabetic letter
 *@i: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int is_letter(int i)
{
	return ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'));
}

/**
 * is_delim - confirms if d is a delimeter character
 * @str: string of delimeter
 * @d: input char
 * Return: bool value true or false
 */

int is_delim(char d, char *str)
{
	while (*str != '\0')
	{
		if (*str == d)
		{
			return (1); /*true*/
		}
		str++;
	}
	return (0); /*false*/
}

