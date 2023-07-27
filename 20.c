#include "shell.h"
/**
 * _strlen - implimentation of the strlen functions
 * @s: parameter
 * Return: as the strlen function should
 */

int _strlen(char *s)
{
	int length = 0;

	if (!s)
		return 0;

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * _strcmp - the exact implimentation of strcmp
 * @s1: first parameter
 * @s2: second paramter
 *
 * Return: chars
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return 0;
	else if (*s1 < *s2)
		return (-1);
	else
		return (1);
}

/**
 * starts_with - helper function
 * @haystack: parameter 1
 * @needle: parameter 2
 *
 * Return: NULL if failure
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}

	return (char *)haystack;
}

/**
 * _strcat - implimentation of strcat
 * @dest: input parameter 1
 * @src: input parameter 2
 *
 * Return: ptr
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return (ret);
}
