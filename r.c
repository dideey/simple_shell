#include "main.h"
/**
 *  *_atoi - function that converts a string to int
 *   *@str: string to be converted
 *    *Return: returns the converted number or 0 on error
 **/
int _atoi(const char *str)
{
	int result = 0, digit;
	bool negative_int = false;

	if (*str == '-')
	{
		negative_int = true;
		str++;
	}
	while (*str)
	{
		digit = *str - '0';
		if (digit >= 0 && digit <= 9)
		{
			result = result * 10 + digit;
		}
		else
		{
			break;
		}
		str++;
	}
	if (negative_int)
	{
		result = -result;
	}
	return (result);
}
/**
 *  *print_error - functiono that prints error message to stderr
 *   *@err: error message to be printed
 **/
void print_error(char *err)
{
	write(2, err, _strlen(err));
}
/**
 *  *str_rev - function that reverses a string
 *   *@str: string to be reversed
 *    *@length: length of string to be reversed
 *     *
 **/
void str_rev(char *str, int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
/**
 *  *to_str - function that converts an int to string
 *   *@num: integer to be converted to string
 *    *@str: string array to store the new string
 *     *
 **/
void to_str(int num, char *str)
{
	int i = 0;
	int digit, neg_int = 0;

	if (num < 0)
	{
		neg_int = 1;
		num = -num;
	}

	while (num > 0)
	{
		digit = num % 10;
		str[i++] = digit + '0';
		num /= 10;
	}

	if (neg_int)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	str_rev(str, i);
}
/**
 *  *error_num - function that prints session number to
 *   *		stderr for error handling
 *    *@num: number to be handled
 **/
void error_num(int num)
{
	char err[1024];

	to_str(num, err);
	print_error(err);
}
