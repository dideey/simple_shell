#include "main.h"
/**
 *  *exit_func - a function that handles the "exit"
 *   *		commands from the user..
 *    *@_argv: array of inputs from the user
 *     *@e_ex: executable for the program error handling
 *      *@sc: session count for error handling
 *       *@copy: string from the prigram to be freed before exiting
 *        *@input: input from the "getline function to be freed"
 *         *	before exiting
 *          *@_environ: custom environmental variables to be
 *           *		freed before exiting the pogram
 *            *Return: returns 2 on error otherwise exits the program
 **/
int exit_func(char **_argv, char *e_ex, int sc, char *copy,
		char *input, list_t *_environ)
{
	char *stat, A, a;
	int stat_value, i;

	if (_argv[1])
	{
		stat = _argv[1];
		for (i = 0; stat[i]; i++)
		{
			for (A = 'A', a = 'a'; A <= 'Z'; A++, a++)
			{
				if (stat[i] == A || stat[i] == a)
				{
					exit_err_msg(_argv, e_ex, sc);
					fflush(stdout);
					return (2);
				}
			}
		}
		stat_value = _atoi(stat);
		if (stat_value < 0 || stat_value > 999999999)
		{
			exit_err_msg(_argv, e_ex, sc);
			fflush(stdout);
			return (2);
		}
		free_list(_environ);
		free(copy);
		free(_argv);
		free(input);
		exit(stat_value);
	}
	free_list(_environ);
	free(copy);
	free(_argv);
	free(input);
	exit(0);
}
