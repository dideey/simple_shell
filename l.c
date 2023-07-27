#include "main.h"
/**
 *  *order - function that checks the order of
 *   *	a "&&" and "||" command
 *    *@token: command to be checked
 *     *Return: returns 2 if "||" command comes
 *      *	first and 0 if "&&" comes first
 *       */
int order(char *token)
{
	int i;

	for (i = 0; token[i]; i++)
	{
		if (token[i] == '|' && token[i + 1] == '|')
			return (2);
		if (token[i] == '&' && token[i + 1] == '&')
			return (0);
	}
	return (0);
}
/**
 *  *get_operators - function that sorts the "&&"
 *   *		and "||" command depending on
 *    *		which comes first
 *     *@token: user command to be checked
 *      *@e_ex: program executable for error handling
 *       *@sc: session count for error handling
 *        *@input: user input to be freed
 *         *@_environ: custom environmental variables for the program
 *          *Return: returns 0 on success and nonzero on error
 *           */
int get_operators(char *token, char *e_ex, int sc, char *input,
		list_t *_environ)
{

	if (order(token) == 2)
	{
		return (or_first(token, e_ex, sc, 0, input, _environ));
	}
	return (and_first(token, e_ex, sc, 0, input, _environ));
}
/**
 *  *and_or_check - a function that checks if a
 *   *		command contains "&&" or "||"
 *    *@token: user command to be checked
 *     *@e_ex: program executable for error handling
 *      *@sc: session count for error handling
 *       *@input: user input to be freed
 *        *@_environ: custom environmental variables for the program
 *         *Return: returns 0 on success and nonzero on error
 *          */
int and_or_check(char *token, char *e_ex, int sc, char *input,
		list_t *_environ)
{
	int i;

	for (i = 0; token[i]; i++)
	{
		if ((token[i] == '&' && token[i + 1] == '&') ||
				(token[i] == '|' && token[i + 1] == '|'))
		{
			return (check_error(token, e_ex, sc, input, _environ));
		}
	}
	return (comment(token, e_ex, sc, _environ));
}
/**
 *  *handle_error - a function that handles error
 *   *		in a "&&" and "||" command
 *    *@arr: array of strings to be checked for
 *     *	"||" and "&&" error
 *      *@input: user command
 *       *@j: for iteration continuation
 *        *@u_input: user input to be freed
 *         *@_environ: custom environmental variables
 *          *@n: for iteration continuation
 *           *@i: for iteration continuation
 *            *@e_ex: program executable for error handling
 *             *@sc: session count for error handling
 *              *Return: returns 0 on success and nonzero on error
 *               */
int handle_error(char **arr, char *input, int j, char *u_input,
		list_t *_environ, int n, int i, char *e_ex, int sc)
{
	int ret_val = 0;

	for (n = 0; arr[n]; n++)
	{
		for (i = 0; arr[n][i]; i++)
		{
			if ((arr[n][i] == '&' && arr[n][i + 1] == '&') &&
					(arr[n][i + 2] == '&' && arr[n][i + 3] == '&'))
			{
				return (and_or_err(e_ex, "&&", sc));
			}
			else if ((arr[n][i] == '|' && arr[n][i + 1] == '|') &&
					(arr[n][i + 2] == '|' && arr[n][i + 3] == '|'))
			{
				return (and_or_err(e_ex, "||", sc));
			}
			else if ((arr[n][i] == '&' && arr[n][i + 1] == '&') &&
					(arr[n][i + 2] == '|' && arr[n][i + 3] == '|'))
			{
				return (and_or_err(e_ex, "||", sc));
			}
			else if ((arr[n][i] == '|' && arr[n][i + 1] == '|') &&
					(arr[n][i + 2] == '&' && arr[n][i + 3] == '&'))
			{
				return (and_or_err(e_ex, "&&", sc));
			}
			else
			{
				ret_val = handle_error_com(arr, n, e_ex, sc);
				if (ret_val != 0)
					return (ret_val);
			}
		}
	}
	return (check_error_comp(arr, input, j, e_ex, u_input, sc, _environ));
}
/**
 *  *check_error - function that checks for error in
 *   *		the "&&" and "||" user command
 *    *@input: command to be checked
 *     *@e_ex: program executable for error handling
 *      *@sc: session count for error handling
 *       *@u_input: user input to be freed
 *        *@_environ: custom environmental variables for the program
 *         *Return: returns 0 on success and nonzero on error
 *          */
int check_error(char *input, char *e_ex, int sc, char *u_input,
		list_t *_environ)
{
	int i = 0, n = 0, j = 0;
	char *token, *str = _strdup(input);
	char **arr = malloc(_strlen(input) * SIZE_OF_CHARP);

	if (arr == NULL)
		return (-1);
	token = _strtok(str, " \t");
	if (token == NULL)
		return (-1);
	while (token)
	{
		arr[i] = _strdup(token);
		i++;
		token = _strtok(NULL, " \t");
	}
	arr[i] = NULL;
	j = (i - 1);
	if ((arr[0][0] == '&' && arr[0][1] == '&'))
	{
		return (error_and_free(str, e_ex, "&&", arr, sc));
	}
	if ((arr[0][0] == '|' && arr[0][1] == '|'))
	{
		return (error_and_free(str, e_ex, "||", arr, sc));
	}
	free(str);
	return (handle_error(arr, input, j, u_input, _environ, n, i, e_ex, sc));
}
