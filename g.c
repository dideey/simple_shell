#include "main.h"
/**
 *  *_setenv - a function that handles the setting of
 *   *		new environmental varibale by the user
 *    *@env: name of the new environmental variable to
 *     *	be set
 *      *@value: value of the variable to be set..
 *       *@_environ: custom environmental varibales for
 *        *		the program which is to be edited
 *         *Return: returns zero on success and nonzero on error
 **/
int _setenv(char *env, char *value, list_t **_environ)
{
	char *env_var;
	list_t *current = *_environ;

	env_var = to_env_var(env, value);
	while (current)
	{
		if (_strncmp(current->data, env_var, _strlen(env) + 1) == 0)
		{
			free(current->data);
			current->data = _strdup(env_var);
			free(env_var);
			return (0);
		}
		current = current->next;
	}
	add_node(_environ, env_var);
	free(env_var);
	return (0);
}
/**
 *  *_unsetenv - a function that deals with the deetion of
 *   *		environmental variables in the program
 *    *@env: name of the environmental varible to be removed
 *     *@_environ: custom environmentals for the program
 *      *		which is to be nodified
 *       *Return: returns zero on success and nonzero on error
 *        *
 *         */
int _unsetenv(char *env, list_t **_environ)
{
	list_t *current = *_environ;
	char *temp = malloc(_strlen(env) + 2);

	if (temp == NULL)
		return (-1);
	_strcpy(temp, env);
	temp = _strcat(temp, "=");
	if (delete_node(temp, &current) == NULL)
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (0);
}
