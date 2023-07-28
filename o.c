#include "main.h"
/**
 *  *_strlen - a function that calculate
 *   *	the length of a string
 *    *@s: string whose length is to be calculated
 *     *Return: returns the lenth of the string
 **/
size_t _strlen(const char *s)
{
	const char *p = s;

	while (*p)
	{
		p++;
	}
	return (p - s);
}
/**
 *  *_strdup - a function that duplicates a
 *   *	string
 *    *@str: string to be duplicated
 *     *Return: returns poiner to the new string
 *      *	on success and NULL on error
 **/
char *_strdup(char *str)
{
	char *new_str;
	size_t len = (_strlen(str) + 1);

	new_str = malloc(len);
	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, str, len);
	return (new_str);
}
/**
 *  *_strcpy - a function that creates a copy
 *   *	of a string
 *    *@dest: destination string where the
 *     *	string is to be copied to
 *      *@src: source string where the string is to
 *       *	be copied from
 *        *Return: returns a pointer to the copied string
 **/
char *_strcpy(char *dest, char *src)
{
	char *ptr_dest = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ptr_dest);
}
/**
 *  *_strcmp - a function that compares two strigs
 *   *@s1: string to be compared
 *    *@s2: string to be compared
 *     *Return: return an integer less than, equal to,
 *      *	or greater than zero if s1 (or the first n
 *       *	bytes thereof) is found, respectively, to
 *        *	be less than, to match, or be greater than s2
 **/
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/**
 *  *_strncmp - a function that compares only the
 *   *	first (at most) n bytes of s1 and s2
 *    *@s1: string to be compared
 *     *@s2: string to be compared
 *      *@n: number of bytes to be compared
 *       *Return: return an integer less than, equal to,
 *        *	or greater than zero if s1 (or the first n
 *         *	bytes thereof) is found, respectively, to
 *          *	be less than, to match, or be greater than s2
 **/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	while (*s1 && (*s1 == *s2) && --n)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
