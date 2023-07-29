#include "main.h"
/**
 *  *and_or_user_input - function that accepts input from
 *   *			useer if command ends with "&&" or "||"
 *    *@input: user input
 *     *@e_ex: executable for the program
 *      *@sc: sesion count for error handlig
 *       *@_environ: custom environmental variable for the program
 *        *Return: returns 0 on success and onzero on error
 **/
int and_or_user_input(char *input, char *e_ex, int sc, list_t *_environ)
{
	int ret_val = 0;
	size_t n = 0;
	ssize_t input_count;
	char *cat_str = NULL;

	while (1)
	{
		_print_str(">");
		fflush(stdout);
		input_count = getline(&cat_str, &n, stdin);
		if (input_count != -1) /*not equal to -1*/
		{
			if (_strcmp(cat_str, "\n") == 0)
				continue;
			if (cat_str[_strlen(cat_str) - 1] == '\n')
			{
				cat_str[_strlen(cat_str) - 1] = '\0';
				if (cat_str[0] == '#')
					continue;
				_strcat(input, cat_str);
				free(cat_str);
				ret_val = semi_colon(input, e_ex, sc, _environ);
				return (ret_val);
			}
			if ((input_count == -1 && EOF) || (input_count == -1 && SIGINT))
			{
				free(cat_str);
				return (and_or_input_err(e_ex, sc));
			}
		}
		else
			return (ret_val);
	}
	return (ret_val);
}
