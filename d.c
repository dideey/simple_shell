#include "main.h"
/**
 *  *free_array - a functiono that frees an array
 *   *		of strings
 *    *@arr: array to be freed
 *     *
 *      */
void free_array(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
/**
 *  *free_list - a function that frees a linked list
 *   *@head: pointer to the head od the list to be
 *    *	freed
 *     */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->data);
		free(temp);
	}
}
/**
 *  *error_and_free - a function that frees a string
 *   *		and an array
 *    *@str: string to be freed
 *     *@e_ex: program executable for error message display
 *      *@i_e: a paramter that contains the string for
 *       *	proper error message display
 *        *@arr: array to be freed
 *         *@sc: session count for proper error handling
 *          *Return: returns 2
 *           */
int error_and_free(char *str, char *e_ex, char *i_e, char **arr, int sc)
{
	free(str);
	free(arr);
	return (and_or_err(e_ex, i_e, sc));
}
/**
 *  *return_and_free - a function that frees a string
 *   *			and an array
 *    *@str: string to be freed
 *     *@arr: array to be freed
 *      *@ret_val: function return value
 *       *Return: returns 0 on success and nonzero otherwise
 *        */
int return_and_free(char *str, char **arr, int ret_val)
{
	free(str);
	free(arr);
	return (ret_val);
}
