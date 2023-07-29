#include "main.h"
/**
 *  *sigintHandler - function that handles the
 *   *		"ctrl + C" command in the
 *    *		user input
 *     *@sig_num: signature number
 *      *
 **/
void sigintHandler(__attribute__((unused)) int sig_num)
{
	signal(SIGINT, sigintHandler);
	_print_str("\n$");
	fflush(stdout);
}
/**
 *  *main - entry function in a c program
 *   *@argc: argument count
 *    *@argv: argument vector
 *     *Return: returns 0 on cuccess and nonzero otherwise
 **/
int main(__attribute__((unused)) int argc, char **argv)
{
	size_t n = 0;
	ssize_t input_count;
	char *input = NULL;
	int sc = 0, ef = 0;
	list_t *_environ = NULL;

	_environ = get_environ(_environ);
	signal(SIGINT, sigintHandler);
	while (1)
	{
		sc++;
		if (isatty(STDIN_FILENO))
		{
			_putchar('$');
			fflush(stdout);
			input_count = getline(&input, &n, stdin);

			if (input_count != -1)
			{
				if (_strcmp(input, "\n") == 0)
					continue;
				if (input[_strlen(input) - 1] == '\n')
					input[_strlen(input) - 1] = '\0';
				ef = semi_colon(input, argv[0], sc, _environ);
			}
			if ((input_count == -1 && EOF) || (input_count == -1 && SIGINT))
			{
				free(input);
				free_list(_environ);
				_putchar('\n');
				fflush(stdout);
				return (ef);
			}
		}
		else
			return (non_interactive(n, input_count, input, sc, argv[0], _environ));
	}
	return (0);
}
/**
 *  *non_interactive - function that handles the user
 *   *		input in noniteractive mode
 *    *@n: size of bytes to be read from the user
 *     *	input
 *      *@input_count: gets the status of the getline function
 *       *@input: input from the user
 *        *@sc: session count for error handling
 *         *@e_ex: program executable  for error handling
 *          *@_environ: custom environmental variables for
 *           *		the program
 *            *Return: returns 0 on success and nonzero on error
 **/
int non_interactive(size_t n, ssize_t input_count, char *input, int sc,
		char *e_ex, list_t *_environ)
{
	int ret_val;

	input_count = getline(&input, &n, stdin);
	if (input_count == -1 || input == NULL)
	{
		free(input);
		free_list(_environ);
		return (-1);
	}
	if (_strcmp(input, "\n") == 0)
	{
		free(input);

		return (-2);
	}
	if (input[_strlen(input) - 1] == '\n')
		input[_strlen(input) - 1] = '\0';
	ret_val = semi_colon(input, e_ex, sc, _environ);
	free(input);
	free_list(_environ);
	return (ret_val);
}
