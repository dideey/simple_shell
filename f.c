#include "main.h"
/**
 *  *comment - a function that handles comments found in
 *   *		the user input
 *    *@input: user input to be checked
 *     *@e_ex: the program executable for proper error display
 *      *@sc: session count for proper error display
 *       *@_environ: custom environmental variables ofr the program
 *        *Return: returns nonzero on error and zero on success
 **/
int comment(char *input, char *e_ex, int sc, list_t *_environ)
{
	int i;

	if (input[0] == '#')
	{
		input[0] = '\0';
		return (0); /*.*/
	}
	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ' && input[i + 1] == '#')
		{
			input[i] = '\0';
			break;
		}
	}
	return (to_argv(input, e_ex, sc, _environ));
}
