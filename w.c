#include "main.h"
/**
 *  *locate_path - a function that seraches for
 *   *		the "PATH=" environmental variable
 *    *@_argv: array of user command strings
 *     *@e_ex: program executable for error handling
 *      *@sc: session count for error handling
 *       *Return: reurns 0 on success snd nonzero on error
 **/
int locate_path(char **_argv, char *e_ex, int sc)
{
	char *path_env, *path_dir;
	int i, j = 0, ret_val;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i];
			break;
		}
	}
	path_dir = malloc(_strlen(path_env) - 5 + 1);
	if (path_dir == NULL)
		return (-1);
	for (i = 0; path_env[i]; i++)
	{
		if (i < 6)
			continue;
		path_dir[j] = path_env[i];
		j++;
	}
	path_dir[j] = '\0';
	ret_val = search_path(path_dir, _argv, e_ex, sc);
	free(path_dir);
	return (ret_val);
}
/**
 *  *search_path - function that seraches for commands
 *   *		executablesin the "PATH=" environment
 *    *@path_dir: the "PATH=" environment value
 *     *@_argv: array of user command strings
 *      *@e_ex: program executable for error handling
 *       *@sc: session count for error handling
 *        *Return: reurns 0 on success snd nonzero on error
 *         *
 **/
int search_path(char *path_dir, char **_argv, char *e_ex, int sc)
{
	int ret_val = 0;
	char *path, *tok_path;

	tok_path = _strtok(path_dir, ":");
	while (tok_path)
	{
		path = malloc(_strlen(tok_path) + _strlen(_argv[0]) + 2);
		if (path == NULL)
		{
			return (-1);
		}
		_strcpy(path, tok_path);
		_strcat(path, "/");
		if (_strncmp(_argv[0], "/", 1) == 0)
		{
			free(path);
			return (_access(_argv[0], _argv, e_ex, sc));
		}
		_strcat(path, _argv[0]);
		ret_val = _access(path, _argv, e_ex, sc);
		free(path);
		if (ret_val != -2)
			break;
		tok_path = _strtok(NULL, ":");
	}
	if (ret_val == -2)
	{
		exec_err_msg(_argv, e_ex, sc);
		fflush(stdout);
		return (127);
	}
	return (ret_val);
}
