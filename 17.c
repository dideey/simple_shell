#include "shell.h"
/**
 * _memset - resets memory
 * @s: the memory pointer
 * @b: where the memory is being reset
 * @n: the number
 * Return: ptr to the reset memory
 */

char *_memset(char *s, char b, unsigned int n)
{
    unsigned int t = 0;

    while (t < n)
    {
        s[t] = b;
        t++;
    }

    return (s);
}

/**
 * ffree - main function is to release the strings
 * @pp: parameter which is actually a double string(str of str)
 */
void ffree(char **pp)
{
    char **b = pp;

    if (!pp)
        return;

    while (*pp != NULL)
    {
        free(*pp);
        pp++;
    }

    free(b);
}

/**
 * _realloc - implimentetion of the realloc function
 * @ptr: its a parameter(ptr)
 * @old_size: descriptive
 * @new_size: parameter 3
 * Return: ptr to un-allocated m.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
 unsigned int copy_size;
 char *new_ptr = malloc(new_size);

    switch (!ptr)
    {
        case 1:
            return malloc(new_size);
    }

    switch (!new_size)
    {
        case 1:
            free(ptr);
            return (NULL);
    }

    switch (new_size == old_size)
    {
        case 1:
            return (ptr);
    }

    
    if (!new_ptr)
        return (NULL);

    copy_size = old_size < new_size ? old_size : new_size;
    memcpy(new_ptr, ptr, copy_size);
    free(ptr);

    return (new_ptr);
}

