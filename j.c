#include "main.h"
/**
 *  *and_or_input_err - a function that displays proper error
 *   *			message when a user exits the input..
 *    *			request caused as a result of command
 *     *			ending with "&&" or "||" improperly
 *      *@e_ex: program executable for proper error display
 *       *@sc: session count for proper error display
 *        *Return: returns 2
 **/
int and_or_input_err(char *e_ex, int sc)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(AND_OR_INPUT_ERR);
	return (2);
}
/**
 *  *cd_err - function that displays proper error for the
 *   *	improper use of the cd command by the user
 *    *@e_ex: program executable for proper error display
 *     *@sc: session count for proper error display
 *      *@dir: directory/path of destination resulting to error
 *       *Return: returns 2
 **/
int cd_err(char *e_ex, int sc, char *dir)
{
	print_error(e_ex);
	print_error(": ");
	error_num(sc);
	print_error(CD_ERROR);
	print_error(dir);
	print_error("\n");
	return (2);
}
