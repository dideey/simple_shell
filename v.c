#include "main.h"
/**
 *  *run_or_logical - functionthat handles the
 *   *		execution of the "||" command
 *    *@newstr: user command to be handled
 *     *@type: used to identify the type of command
 *      *	to be executed
 *       *@e_ex: program executable for error handling
 *        *@sc: session count for error handling
 *         *@_environ: custom environmental variables for the program
 *          *Return: returns 0 on succeess and nonzero on error
 **/
int run_or_logical(char *newstr, char type, char *e_ex,
		int sc, list_t *_environ)
{
	char *token, *saveptr;
	int ret_val = 0;

	token = _strtok_r(newstr, ";", &saveptr);
	if (token == NULL)
	{
		return (-1);
	}
	if (type == '|')
	{
		while (token)
		{
			ret_val = comment(token, e_ex, sc, _environ);
			if (ret_val == 0)
				break;
			token = _strtok_r(NULL, ";", &saveptr);
		}
	}

	return (ret_val);
}
/**
 *  *or_operator - function that hanmdles the "||"
 *   *		command in the useer input
 *    *@token: user input to be checked
 *     *@e_ex: program executable for error handling
 *      *@sc: session count for error handling
 *       *@_environ: custom environmental variables for the program
 *        *Return: returns 0 on succeess and nonzero on error
 **/
int or_operator(char *token, char *e_ex, int sc, list_t *_environ)
{
	int i, j = 0, size = _strlen(token), ret_val = 0;
	char *newstr = malloc(size + 1);

	if (newstr == NULL)
		return (-1);
	for (i = 0; token[i]; i++)
	{
		if (token[i] == '|' && token[i + 1] == '|')
		{
			i++;
			token[i] = ';';
		}
		newstr[j] = token[i];
		j++;
	}
	newstr[j] = '\0';

	ret_val = run_or_logical(newstr, '|', e_ex, sc, _environ);

	free(newstr);
	return (ret_val);
}
/**
 *  *or_in_and - a function that handles "||" commands
 *   *		found within "&&" commands
 *    *@i: for iteration continuaion
 *     *@token: user input to be checked
 *      *@e_ex: program executable for error handling
 *       *@sc: session count for error handling
 *        *@ret_val: function return value
 *         *@input: user input to be freed
 *          *@_environ: custom environmental variables for the program
 *           *Return: returns 0 on succeess and nonzero on error
 **/
int or_in_and(int i, char *token, char *e_ex, int sc, int ret_val,
		char *input, list_t *_environ)
{
	char *newstr = NULL;
	int n = 0;

	for (; token[i]; i++)
	{
		if ((token[i] == '&' && token[i + 1] == '&'))
		{
			newstr[n] = '\0';
			if (ret_val != 0)
				or_operator(newstr, e_ex, sc, _environ);
			free(newstr);
			and_first(token, e_ex, sc, i, input, _environ);
			return (i);
		}

		if (newstr == NULL)
		{
			newstr = malloc(SIZE_OF_CHAR * (_strlen(token) + 1));
			if (newstr == NULL)
			{
				return (-1);
			}
		}

		newstr[n] = token[i];
		n++;
	}
	newstr[n] = '\0';
	if (ret_val != 0)
		or_operator(newstr, e_ex, sc, _environ);
	free(newstr);
	return (i);
}
/**
 *  *or_first - function that handles user input that has
 *   *		the "||" command first
 *    *@token: command string to be handled
 *     *@e_ex: program executable for error handling
 *      *@sc: session count for errror handling
 *       *@i: for iteration continuation
 *        *@input: user input to be freed
 *         *@_environ: custom environmental variables for the program
 *          *Return: returns 0 on succeess and nonzero on error
 **/
int or_first(char *token, char *e_ex, int sc, int i, char *input,
		list_t *_environ)
{
	char *newstr = NULL;
	int j = 0, n = 0, len = _strlen(token), ret_val = 0;

	for (; token[i]; i++)
	{
		if ((token[i] == '&' && token[i + 1] == '&'))
		{
			newstr[j] = '\0';
			ret_val = or_operator(newstr, e_ex, sc, _environ);
			i = and_in_or(i, token, e_ex, sc, input, _environ);
			free(newstr);
			newstr = NULL;

			if (i >= len)
				return (ret_val);
			j = 0;
			n++;
			if (i == -1)
				return (-1);
		}
		if (newstr == NULL)
		{
			newstr = malloc(SIZE_OF_CHAR * (_strlen(token) + 1));
			if (newstr == NULL)
			{
				return (-1);
			}
		}
		newstr[j] = token[i];
		j++;
	}
	newstr[j] = '\0';
	if (n == 0)
	{
		if (newstr != NULL)
			ret_val = or_operator(newstr, e_ex, sc, _environ);
	}
	free(newstr);
	return (ret_val);
}
