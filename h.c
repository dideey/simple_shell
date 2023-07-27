#include "main.h"
/**
 *  *_strtok - a function that tokenizes a string
 *   *	using provide delimeters
 *    *@str: striing to be tokenized
 *     *@delim: delimeter to tokenize the string
 *      *Return: returns return a pointer to the next
 *       *	token nad NULL if none is found
 *        */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start;
	char *token_end;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL)
		return (NULL);
	token_start = next_token;
	while (*token_start != '\0' && _strchr(delim, *token_start) != NULL)
		token_start++;
	if (*token_start == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	token_end = token_start + 1;
	while (*token_end != '\0' && _strchr(delim, *token_end) == NULL)
		token_end++;
	if (*token_end != '\0')
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
	else
		next_token = NULL;

	return (token_start);
}
/**
 *  *_strcspn - a function that calculates the
 *   *		length of the initial segment
 *    *		of str1 which consists entirely
 *     *		of bytes not in str2
 *      *@str1: string to be checked
 *       *@str2: string to be chaecked
 *        *Return: returns the number of bytes in the
 *         *	initial segment of str1 which consist
 *          *	only of bytes from str2.
 *           */
size_t _strcspn(const char *str1, const char *str2)
{
	size_t count = 0;
	const char *p;

	for (; *str1; ++str1)
	{
		for (p = str2; *p; ++p)
		{
			if (*str1 == *p)
			{
				return (count);
			}
		}
		++count;
	}

	return (count);
}
/**
 *  *_realloc - a function that reallocates memory to
 *   *		a pointer
 *    *@ptr: pointer whose memory is to be modified
 *     *@size: size of the memoru to be reallocated
 *      *Return: returns a pointer to the new memory
 *       *	on success and NULL no error
 *        */
void *_realloc(void *ptr, size_t size)
{
	size_t old_size;
	void *new_ptr = NULL;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(size));
	}

	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	old_size = malloc_usable_size(ptr);
	_memcpy(new_ptr, ptr, old_size < size ? old_size : size);
	free(ptr);

	return (new_ptr);
}
/**
 *  *_strspn - function calculates the length (in bytes)
 *   *	of the initial segment of str which consists
 *    *	entirely of bytes in set.
 *     *@str: string for the calculation
 *      *@set: string to be checked
 *       *Return: returns the number of bytes in the initial
 *        *	segment of s which are not in the string reject
 *         *
 *          */
size_t _strspn(const char *str, const char *set)
{
	size_t len = 0;
	const char *p = set;

	while (*str)
	{
		while (*p && *p != *str)
		{
			p++;
		}
		if (!*p)
		{
			return (len);
		}
		p = set;
		len++;
		str++;
	}

	return (len);
}
/**
 *  *_memcpy - a function that copies a specified
 *   *		amount of memory from src to dest
 *    *@dest: destination where the memory is to be
 *     *	copied to
 *      *@src: src where the memori is to be copied from
 *       *@n: size of memory to be copied to dest
 *        *Return: returns a pointer to the copied memry
 *         */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	for (i = 0; i < n; ++i)
	{
		d[i] = s[i];
	}

	return (dest);
}
