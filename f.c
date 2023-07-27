#include "main.h"
/**
 *  *_print_str - a function that prints strings;
 *   *@str: string to be printed
 *    *
 *     */
void _print_str(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
}
/**
 *  *_print_int - function that prints an int
 *   *@num: the integer to be printed
 *    *
 *     */
void _print_int(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num > 9)
	{
		_print_int(num / 10);
	}
	_putchar(num % 10 + '0');
}
/**
 *  *print_list - a function that prints the vaues
 *   *		in a linked list
 *    *@head: pointer to the head of the list node to
 *     *	be printed
 *      *
 *       */
void print_list(list_t *head)
{
	while (head)
	{
		_print_str(head->data);
		_putchar('\n');
		head = head->next;
	}
}
/**
 *  *_getenv - a function that get a specified value
 *   *		of an environmental variable in
 *    *		the custom custom environmental
 *     *		variables
 *      *@name: name of the variabel specified
 *       *@_environ: environmental variables to be searched
 *        *Return: retruns the environmental value of the variable
 *         *	if found and  NULL if none is found
 *          */
char *_getenv(const char *name, list_t *_environ)
{
	char *env_var;
	int len;

	if (name == NULL)
	{
		return (NULL);
	}

	while (_environ)
	{
		env_var = _environ->data;
		len = _strlen(name);
		if (_strncmp(env_var, name, len) == 0 && env_var[len] == '=')
		{
			return (&env_var[len + 1]);
		}
	}

	return (NULL);
}
/**
 *  *to_env_var - a function that converts two string
 *   *		to the pattern of an environmental
 *    *		varble and its value
 *     *@str1: Name of the environmental variable
 *      *@str2: name of the envirnmental value
 *       *Return: returns a pointer to the converted string
 *        */
char *to_env_var(const char *str1, const char *str2)
{
	int str1_len = _strlen(str1);
	int str2_len = _strlen(str2);
	int i;
	char *result = malloc(str1_len + str2_len + 2);

	if (result == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < str1_len; i++)
	{
		result[i] = str1[i];
	}
	result[str1_len] = '=';
	for (i = 0; i < str2_len; i++)
	{
		result[str1_len + 1 + i] = str2[i];
	}
	result[str1_len + str2_len + 1] = '\0';
	return (result);
}
