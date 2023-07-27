#include "main.h"
/**
 *cd_command - a function that handles the navigation of
 *		paths and directories by the program
 *@path: path specified by the user
 *@e_ex: the executable for the program for proper error
 *	display
 *@sc: session counter for proper error display
 *@_environ: custom environmental variables for the program
 *Return: reurns 0 on success and nonzero on error
 */
int cd_command(char *path, char *e_ex, int sc, list_t *_environ)
{
	char *home_dir, *oldpwd;

	if (path == NULL)
	{
		home_dir = _getenv("HOME", _environ);
		if (chdir(home_dir) == -1)
			return (cd_err(e_ex, sc, path));
		return (0);
	}
	if (_strcmp(path, "-") == 0)
	{
		oldpwd = _getenv("OLDPWD", _environ);
		if (chdir(oldpwd) == -1)
			return (cd_err(e_ex, sc, path));
	}
	if (chdir(path) == -1)
		return (cd_err(e_ex, sc, path));
	return (0);
}
