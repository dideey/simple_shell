#include "main.h"
/**
 *  *create_node - a function that creates a node for
 *   *		storing an environmental variable
 *    *@data: daat to be stored in the node
 *     *Return: returns a pointer to the new node on
 *      *	success and NULL on error
 *       *
 *        */
list_t *create_node(char *data)
{
	list_t *new_node = malloc(SIZE_OF_LIST_T);

	if (new_node == NULL)
		return (NULL);
	new_node->data = _strdup(data);
	new_node->next = NULL;
	return (new_node);
}
/**
 *  *delete_node - a function that deletes a node hat contains
 *   *		an environmental variable and frees its pointer
 *    *@env: content of the nde that is used to determine the node
 *     *	to be deleted
 *      *@_environ: custom environmental variables which is
 *       *		to be modified
 *        *Return: returns a pointer to the new environmental variables on
 *         *	success and NULL on error
 *          */
list_t *delete_node(char *env, list_t **_environ)
{
	list_t *current = *_environ, *prev = NULL;

	if (*_environ == NULL)
	{
		_print_str("Variable(s) Not set\n");
		free(env);
		return (NULL);
	}
	while (current)
	{
		if (_strncmp(current->data, env, _strlen(env)) == 0)
		{
			if (prev == NULL)
			{
				*_environ = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			free(current->data);
			free(current);
			return (*_environ);
		}
		prev = current;
		current = current->next;
	}
	_print_str("Environment does not exist\n");
	free(env);
	return (*_environ);
}
/**
 *  *add_node - a function that adds a new node containing
 *   *		an environmental variable and its value
 *    *		to the list
 *     *@head: pointer t othe head of the node to be added
 *      *@data: data to be added to the new node
 *       *Return: returns a pointer to the head od the new
 *        *	added node on success and NULL on error
 *         */
list_t *add_node(list_t **head, char *data)
{
	list_t *new_node = create_node(data);
	list_t *current;

	if (new_node == NULL)
		return (NULL);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (*head);
}
/**
 *  *get_environ - function that creates the custom
 *   *		environmenatal variables for the
 *    *		program
 *     *@_environ: the custom environmental variables
 *      *		to be created
 *       *
 *        *Return: returns a pointer to the created
 *         *	environmental variables
 *          */
list_t *get_environ(list_t *_environ)
{
	char **env = environ;

	while (*env)
	{
		add_node(&_environ, *env);
		env++;
	}

	return (_environ);
}
