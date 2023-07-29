#include "main.h"
/**
 *  *exec_err_msg - a function that displays meaningful
 *   *		command execution error message
 *    *@_argv: array of command strings to be used for
 *     *	error display
 *      *@sc: session count for displaying meaningful
 *       *	error message
 *        * @e_ex: the program executable for proper error
 *         *	message display
 *          *
 **/
void exec_err_msg(char **_argv, char *e_ex, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(": ");
	print_error(_argv[0]);
	print_error(EXEC_ERR);
}
/**
 *  *exit_err_msg - a function that displays meaningful
 *   *		exit error message on error
 *    *@_argv: array of command strings to be used for
 *     *	error display
 *      *@sc: session count for displaying meaningful
 *       *	error message
 *        *@e_ex: the program executable for proper error
 *         *	message display
 *          *
 **/
void exit_err_msg(char **_argv, char *e_ex, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(EXIT_ERROR);
	print_error(_argv[1]);
	print_error("\n");
}
/**
 *  *setenv_usage_err_msg - a function that displays meaningful
 *   *			error on "setenv" command usage
 *    *@e_ex: the program executable for proper error
 *     *	message display
 *      *
 **/
void setenv_usage_err_msg(__attribute__((unused)) char *e_ex)
{
	print_error("Usage: setenv <VARIABLE> <VALUE>\n");
}
/**
 *  *unsetenv_usage_err_msg - a function that displays meaningful
 *   *			error on "unsetenv" command usage
 *    *@e_ex: the program executable for proper error
 *     *	message display
 **/
void unsetenv_usage_err_msg(__attribute__((unused)) char *e_ex)
{
	print_error("Usage: unsetenv <VARIABLE>\n");
}
/**
 *  *and_or_err - a function that displays meaningful
 *   *		error for "&&" and "||" commands
 *    *@e_ex: the program executable for proper error
 *     *	message display
 *      *@ao: a paramerter that holds the "&&" or "||"
 *       *	sign for proper meaningful error display
 *        *@sc: session count for proper error display
 *         *Return: returns 2
 **/
int and_or_err(char *e_ex, char *ao, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(LOGIC_ERROR);
	print_error(ao);
	print_error(LOGIC_ERRND);
	return (2);
}
