#include "main.h"
/**
 *  *to_argv - a function that converts a user input into
 *   *		an array of strings for execution
 *    *@input: input from the user
 *     *@e_ex: program executable for proper error display
 *      *@sc: session count for proper error display
 *       *@_environ: custom environmental variables for the program
 *        *Return: returns 0 on success and nonzero on error
 **/
int to_argv(char *input, char *e_ex, int sc, list_t *_environ)
{
	char *token, **_argv = NULL, *copy = _strdup(input);
	int i = 0, ret_val;

	if (copy == NULL)
		return (-1);
	token = _strtok(copy, " \t");
	if (token == NULL)
	{
		free(copy);
		return (-1);
	}
	while (token)
	{
		if (*token != '\0')
		{
			_argv = _realloc(_argv, (i + 1) * SIZE_OF_CHARP);
			if (_argv == NULL)
			{
				free(copy);
				free(_argv);
				return (-1);
			}
			_argv[i] = token;
			i++;
		}
		token = _strtok(NULL, " \t");
	}
	_argv = _realloc(_argv, (i + 1) * SIZE_OF_CHARP);
	if (_argv == NULL)
	{
		free(copy);
		free(_argv);
		return (-1);
	}
	_argv[i] = NULL;
	ret_val = _identify(_argv, e_ex, sc, copy, input, _environ);
	free(copy);
	free(_argv);
	return (ret_val);
}
