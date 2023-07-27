#include "main.h"
/**
 *  *_strncpy - a functiono that copies n bytes of
 *   *	strings from src to dest string
 *    *@dest: destination where the string is to be
 *     *	copied to
 *      *@src: souce of where the string is to be copied
 *       *	from
 *        *@n: number of bytes to be copied from the src
 *         *	string
 *          *Return: returns a pointer to the dest string
 *           */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 *  *_strchr - a function that searches for the first
 *   *	occurance of a character in a string
 *    *@str: string to be searched
 *     *@c: charcter to search for
 *      *Return: return a pointer to the matched character
 *       *	or NULL if the character is not found
 *        */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
/**
 *  *_strcat - a function that concatenates two strings
 *   *@dest: the string which the src string is to be
 *    *	concatenated to
 *     *@src: string to be concatenated to the dest string
 *      *Return: returns a pointer to the dst string
 *       */
char *_strcat(char *dest, const char *src)
{
	char *dest_start = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}
/**
 *  *_strtok_r - a function that tokenizes a string using
 *   *		provided delimeter
 *    *@str: strng to be tokenized
 *     *@delim: delimeter which the string is to be
 *      *	tokenized with
 *       *@saveptr: pointer to a char variable that is used by
 *        *		the function in order to maintain context
 *         *		between successive calls that parse the
 *          *		same string
 *           *Return: return a pointer to the next token, or NULL
 *            *	if there are no more tokens
 *             */
char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *token_start;
	char *token_end;

	if (str != NULL)
		*saveptr = str;

	if (*saveptr == NULL || **saveptr == '\0')
		return (NULL);

	token_start = *saveptr;
	token_end = _strpbrk(token_start, delim);

	if (token_end != NULL)
	{
		*token_end = '\0';
		*saveptr = token_end + 1;
	}
	else
		*saveptr = NULL;
	return (token_start);
}
/**
 *  *_strpbrk - a function that searches for the first
 *   *	occurence os a string in a string
 *    *@s: string to search for
 *     *@accept: string to be searched
 *      *Return: retruns a apointer to the found string
 *       *	or NULL if none is found
 *        */
char *_strpbrk(const char *s, const char *accept)
{
	const char *a;

	if (s == NULL || accept == NULL)
		return (NULL);

	while (*s != '\0')
	{
		a = accept;
		while (*a != '\0')
		{
			if (*s == *a)
			{
				return ((char *)s);
			}
			a++;
		}
		s++;
	}

	return (NULL);
}
