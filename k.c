#include "main.h"
/**
 *  *_execute - function that handles thet execution of
 *   *		all user commands
 *    *@path: pathfor the commands executables
 *     *@_argv: array of commands entered by the user
 *      *@e_ex: executable of the program for proper error display
 *       *@sc: session count for the program
 *        *Return: returns 0 on success and nonzero otherwise
 **/
int _execute(char *path, char **_argv, char *e_ex,
		__attribute__((unused)) int sc)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{

		if (execve(path, _argv, environ) == -1)
		{
			perror(e_ex);
			return (0);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror(e_ex);
		}
		if (status == 512)
		{
			return (2);
		}
		else if (status == 256)
			return (1);
	}
	return (0);
}
/**
 *  *_access - a function that checks if a command
 *   *		is fount in the path variable
 *    *		directories
 *     *@path: path to be checked for the commads existance
 *      *@_argv: user commads array
 *       *@e_ex: executable of the program for proper error display
 *        *@sc: session count for the program
 *         *Return: returns 0 on success and -2 otherwise
 **/
int _access(char *path, char **_argv, char *e_ex, int sc)
{
	if (access(path, X_OK) == 0)
	{
		return (_execute(path, _argv, e_ex, sc));
	}
	return (-2);
}
