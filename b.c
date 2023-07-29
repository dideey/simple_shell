#include "main.h"
/**
 *  *run_and_logical - a function that handles the execution of the
 *   *			"&&" operator
 *    *@newstr: user command that contins the "&&" commands
 *     *@type: a parameter which helps to indicate the typep of
 *      *	command entered which in this case is a/an "&" command
 *       *@e_ex: a parameter that holds the program executable file
 *        *	for the purpose of proper error display
 *         *@sc: sesion counter for error display
 *          *@_environ: parameter that handles custom environmental
 *           *		variable for the program
 *            *Return: returns a nonzero value on error and zero on success
 **/
int run_and_logical(char *newstr, char type, char *e_ex, int sc,
		list_t *_environ)
{
	char *token, *saveptr;
	int ret_val = 0;

	token = _strtok_r(newstr, ";", &saveptr);
	if (token == NULL) /*if token is null*/
	{
		return (-1);
	}
	if (type == '&')
	{
		while (token)
		{
			ret_val = comment(token, e_ex, sc, _environ);
			if (ret_val != 0)
				break;
			token = _strtok_r(NULL, ";", &saveptr);
		}
	}

	return (ret_val);
}
/**
 *  *and_operator - a functiono that handles commands that has the "&&"
 *   *		operator and prepares it for execution
 *    *@token: the user command that has the operators
 *     *@e_ex: a parameter that holds the program executable file
 *      *      for the purpose of proper error display
 *       *@sc: sesion counter for error display
 *        *@_environ: parameter that handles custom environmental
 *         *		variable for the program
 *          *Return: returns a nonzero value on error and zero on success
 **/
int and_operator(char *token, char *e_ex, int sc, list_t *_environ)
{
	int i, j = 0, size = _strlen(token), ret_val = 0;
	char *newstr = malloc(size + 1);

	if (newstr == NULL)
		return (-1);
	for (i = 0; token[i]; i++)
	{
		if (token[i] == '&' && token[i + 1] == '&')
		{
			i++;
			token[i] = ';';
		}
		newstr[j] = token[i];
		j++;
	}
	newstr[j] = '\0';
	ret_val = run_and_logical(newstr, '&', e_ex, sc, _environ);
	free(newstr);
	return (ret_val);
}

/**
 *  *and_in_or - a function that handles the "&&"
 *   *		comands found withhin the "||" commands
 *    *@i: for iteration continuation
 *     *@token: the user command that has the operators
 *      *@e_ex: a parameter that holds the program executable file
 *       *	for the purpose of proper error display
 *        *@sc: sesion counter for error display
 *         *@input: input from the user that needs to be freed
 *          *@_environ: parameter that handles custom environmental
 *           *		variable for the program
 *            *Return: returns a nonzero value on error and zero on success
 **/

int and_in_or(int i, char *token, char *e_ex, int sc, char *input,
		list_t *_environ)
{
	char *newstr = NULL;
	int n = 0, ret_val;

	for (; token[i]; i++)
	{
		if ((token[i] == '|' && token[i + 1] == '|'))
		{
			newstr[n] = '\0';
			ret_val = and_operator(newstr, e_ex, sc, _environ);
			free(newstr);
			if (ret_val != 0)
				or_first(token, e_ex, sc, i, input, _environ);
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
	and_operator(newstr, e_ex, sc, _environ);
	free(newstr);
	return (i);
}
/**
 *  *and_first - a functiono that handles commands that has the "&&"
 *   *		before the "||"
 *    *@token: the user command that has the operators
 *     *@e_ex: a parameter that holds the program executable file
 *      *	for the purpose of proper error display
 *       *@sc: sesion counter for error display
 *        *@i: for iteration continuation
 *         *@input: input from the user that needs to be freed
 *          *@_environ: parameter that handles custom environmental
 *           *		variable for the program
 *            *Return: returns a nonzero value on error and zero on success
 **/
int and_first(char *token, char *e_ex, int sc, int i, char *input,
		list_t *_environ)
{
	char *newstr = NULL;
	int j = 0, n = 0, len = _strlen(token), ret_val = 0;

	for (; token[i]; i++)
	{
		if ((token[i] == '|' && token[i + 1] == '|'))
		{
			newstr[j] = '\0';
			ret_val = and_operator(newstr, e_ex, sc, _environ);
			i = or_in_and(i, token, e_ex, sc, ret_val, input, _environ);
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
	if (n == 0)
	{
		if (newstr != NULL)
			newstr[j] = '\0';
		ret_val = and_operator(newstr, e_ex, sc, _environ);
	}
	free(newstr);
	return (ret_val);
}
