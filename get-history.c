#include "shell.h"
/**
 * get_history_file - fetchs the hist
 * @info: reccurent parameter
 * Return: its all about thehistory and so is the return string
 */
char *get_history_file(info_t *info)
{
	char *buffer, *directory;

	size_t dir_len, hist_file_len, buffer_size;
	size_t i;

	directory = _getenv(info, "HOME=");
	if (!directory)
		return (NULL);
	dir_len = _strlen(directory);
	hist_file_len = _strlen(HIST_FILE);
	buffer_size = dir_len + hist_file_len + 2;
	buffer = malloc(buffer_size * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	for (i = 0; i < dir_len; i++)
		buffer[i] = directory[i];
	buffer[dir_len] = '/';

	for (i = 0; i < hist_file_len; i++)
		buffer[dir_len + 1 + i] = HIST_FILE[i];
	buffer[dir_len + 1 + hist_file_len] = '\0';
	return (buffer);
}
/**
 * write_history - makes a new file containing the history
 * @info: usual input
 * Return: true if pass and -1 if not
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = info->history;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);

	while (node)
	{
		switch (_putsfd(node->str, fd))
		{
			case -1:
				return (-1);
			case 0:
				_putfd('\n', fd);
				break;
			default:
				break;
		}
		node = node->next;
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
/**
 * read_history - does as describe
 * @info: usual input
 * Return: false
 */

int read_history(info_t *info)
{
	int index = 0, last = 0, line_count = 0;
	ssize_t file_descriptor, read_length, file_size = 0;
	struct stat file_stat;
	char *buffer = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	free(filename);
	if (file_descriptor == -1)
		return (0);
	if (!fstat(file_descriptor, &file_stat))
		file_size = file_stat.st_size;
	if (file_size < 2)
		return (0);
	buffer = malloc(sizeof(char) * (file_size + 1));
	if (!buffer)
		return (0);
	read_length = read(file_descriptor, buffer, file_size);
	buffer[file_size] = '\0';
	if (read_length <= 0)
	{
		free(buffer);
		close(file_descriptor);
		return (0); }
	close(file_descriptor);
	index = 0;
	for (; index < file_size; index++)
	{
		if (buffer[index] == '\n')
		{
			buffer[index] = '\0';
			build_history_list(info, buffer + last, line_count++);
			last = index + 1; }
	}
	do {
		delete_node_at_index(&(info->history), 0);
	} while (--info->histcount >= HIST_MAX);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list - description
 * @info: input init
 * @buf: buffer
 * @linecount: parameter 3
 * Return: Always
 **/

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);
	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - description to the t
 * @info: Same old input
 * Return: info->histcount = i
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}

