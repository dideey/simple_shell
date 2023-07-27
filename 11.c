#include "shell.h"
/**
 * clear_info - sets everything to null
 * @info: input parameter
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */

void set_info(info_t *info, char **av)
{
    info->fname = av[0];

    if (info->arg != NULL)
    {
        info->argv = strtow(info->arg, " \t");
        if (info->argv == NULL)
        {
            info->argv = malloc(sizeof(char *));
            if (info->argv != NULL)
            {
                info->argv[0] = _strdup(info->arg);
                info->argv[1] = NULL;
            }
        }
        else
        {
            int j = 0;
            while (info->argv[j] != NULL)
            {
                j++;
            }
            info->argc = j;

            replace_alias(info);
            replace_vars(info);
        }
    }
}

/**
 * free_info - releases the info node
 * @info: normal input
 * @all: parameter 2
 */
void free_info(info_t *info, int all)
{
    ffree(info->argv);
    info->argv = NULL;
    info->path = NULL;

    if (all)
    {
        if (info->cmd_buf == NULL)
            free(info->arg);

        free_list(&(info->env));
        free_list(&(info->history));
        free_list(&(info->alias));

        ffree(info->environ);
        info->environ = NULL;

        bfree((void **)info->cmd_buf);

        if (info->readfd > 2)
            close(info->readfd);

        _putchar(BUF_FLUSH);
    }
}

