#include "shell.h"
/**
 * list_len - identify the linked lists' length
 * @v: identifier to the root node
 * Return: list length
 */

size_t list_len(const list_t *v)
{
	size_t s = 0;
	const list_t *node;

	for (node = v; node != NULL; node = node->next)
	{
		s++;
	}

	return (s);
}

/**
 * list_to_strings - brings back an array of strings from list str
 * @head: initial node's ptr
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	size_t size = list_len(head);
	char **strs = NULL;
	size_t i;

	if (!head || size == 0)
		return (NULL);

	strs = malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL); /*if not strs null*/

	for (i = 0; i < size; i++)
	{
		strs[i] = _strdup(head->str);
		if (!strs[i])
		{
			while (i > 0)
				free(strs[--i]);
			free(strs);
			return (NULL);
		}
		head = head->next;
	}

	strs[i] = NULL;
	return (strs);
}
/**
 * print_list - all elements of a list_t linked list are printed
 * @b: first node's ptr
 * Return: list's size
 */
size_t print_list(const list_t *b)
{
	size_t count = 0;

	for (; b; b = b->next)
	{
		_puts(convert_number(b->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(b->str ? b->str : "(nil)");
		_puts("\n");
		count++;
	}

	return (count);
}
/**
 * node_starts_with - returns a node whose string prefixes
 * @node: simple parameter
 * @prefix: aligned string
 * @q: follows aligned prefix
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char q)
{
	for (; node; node = node->next)
	{
		char *p = starts_with(node->str, prefix);

		if (p && ((q == -1) || (*p == q)))
			return (node);
	}

	return (NULL);
}
/**
 * get_node_index - node index
 * @head: ptr  head
 * @node: ptr  node
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	ssize_t index = 0;
	list_t *current = head;

	while (current != NULL)
	{
		if (current == node)
		{
			return (index);
		}
		index++;
		current = current->next;
	}

	return (-1);
}
