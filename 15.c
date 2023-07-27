#include "shell.h"
/**
 * bfree - it lets the buffer space go
 * @ptr: parameter ptr
 * Return: bool values
 */
int bfree(void **ptr)
{
	if (!ptr)
		return (0);

	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return 1;
	}

	return (0);
}

