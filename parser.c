#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * is_cmd - checks if input is cmd
 * @info: pararmeter
 * @path: 2nd parameter
 * Return: bool values
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0); /*return value*/

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - twins
 * @pathstr: parameter 1
 * @start: parameter 2
 * @stop: parameter 3
 * Return: pointer to the duplicate
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	char *buf;
	int length = stop - start;
	int k, i;

	k = 0;

	buf = (char *)malloc((length + 1) * sizeof(char));

	if (buf == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}

	for (i = start; i < stop; i++)
	{
		if (pathstr[i] != ':')
		{
			buf[k] = pathstr[i];
			k++;
		}
	}

	buf[k] = '\0';

	return (buf);
}

/**
 * find_path - looks for command along
 * @info: parameter 1
 * @pathstr: parameter 2
 * @cmd: command
 * Return: as it should the path
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
