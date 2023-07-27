#include "main.h"
/**
 *  *semi_colon - function that handles
 *   *		the ";" in user input
 *    *@input: user command input
 *     *@e_ex: program executable for error
 *      *	handling
 *       *@sc: session count for error handling
 *        *@_environ: custom environmenta variables
 *         *		for the program
 *          *Return: returns 0 on success and nonzero
 *           *	on error
 *            */
int semi_colon(char *input, char *e_ex, int sc, list_t *_environ)
{
	char *token /* , *copy = _strdup(input) */, *saveptr;
	int ret_val;

	if (input[0] == ';')
		return (and_or_err(e_ex, ";", sc));

	token = _strtok_r(input, ";", &saveptr);
	if (token == NULL)
	{
		return (-1);
	}
	while (token)
	{
		ret_val = and_or_check(token, e_ex, sc, input, _environ);
		token = _strtok_r(NULL, ";", &saveptr);
	}
	return (ret_val);
}
