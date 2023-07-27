#include "shell.h"
/**
 * is_chain - the exact implimentation of is_chain function
 * @info: input parameter 1
 * @buf: input parameter 2
 * @p: input parameter 3
 *
 * Return: bool values
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0; 
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}
/**
 * check_chain - runs through a command
 * @info: input parameter 1
 * @buf: input parameter 2
 * @p: input parameter 3
 * @i: input parameter 4
 * @len: lenght
 *
 * Return: nada
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;
	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	*p = j;
}
/**
 * replace_alias - replacces the alias
 * @info: parameter
 *
 * Return: true or false
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;
	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
/**
 * replace_vars - replaces variables
 * @info: input parameter 
 *
 * Return: bool values
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;
	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));
	}
	return (0);
}
/**
 * replace_string - replaces strings and frees them
 * @old: adress parameter
 * @new: new string
 *
 * Return: bool values
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
