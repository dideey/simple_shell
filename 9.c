#include "shell.h"
#include <stdlib.h>
/**
 * _setenv - Create a new environ or alter one that exists
 * @info: recurrent
 * @var: string environment variable
 * @value: string environment value
 * Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value) {
	char *buf = NULL;
	list_t *node;
	char *t;

	if (!var || !value) /*Check if the variable name and value are provided*/
		return 0;

	buf = malloc(_strlen(var) + _strlen(value) + 2); /*Allocate memory for the buffer to store the variable assignment*/
	if (!buf)
		return 1;

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);

	node = info->env;
	for (; node; node = node->next) {
		t = starts_with(node->str, var);
		if (t && *t == '=') {
			/*If the variable already exists, update its value*/
			free(node->str);  
			node->str = buf;
			info->env_changed = 1;
			return 0;
		}
	}

	/* Adding a new node at the end of the linked list */
	node = info->env;
	if (!node) {
		add_node_end(&(info->env), buf, 0);
	} else {
		while (node->next)
			node = node->next;
		node->next = malloc(sizeof(list_t));
		if (!node->next) {
			free(buf);
			return 1;
		}
		node->next->str = buf;
		node->next->next = NULL;
	}

	info->env_changed = 1; /*Set the environment change flag and return success*/
	return 0;
}
/**
 * get_environ - representation of the string's surrounding is returned
 * @info: provide a prospectiveargument which keeps a consistent function prototype
 * Return: Always 0
 */


/* Declare the free_string_array function*/

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
/**
 * _unsetenv - Get rid of the variable env
 * @info: Recurrent
 *  Return: bool values
 *  @var: the string env var property
 */
int _unsetenv(info_t *info, char *var) 
{
	list_t *node = info->env;
	size_t i = 0;
	char *t;

	if (!node || !var)
		return 0;
	/*Traverse the linked list to find the variable to be removed*/
	for (; node; node = node->next, i++) {
		t = starts_with(node->str, var);
		if (t && *t == '=') {
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0; /*Reset the index and the node pointer to traverse the list again*/
			node = info->env;
		}
	}

	return (info->env_changed);
}
