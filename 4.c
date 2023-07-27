#include "shell.h"
/**
* _myenv - shows the environment printout
* @info: To retain the constant function prototype
* a structure with potential arguments is employed.
* Return: Always 0
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}
/**
 * _getenv - obtains the value of a variable in the environ
 * @info: recurrent
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *value = NULL;
    
    while (node && !value)
    {
        value = starts_with(node->str, name);
        node = node->next;
    }
    
    return (value);
}
/**
 * _mysetenv - Set up a new environment variable
 * or alter one that already exists
 * @info: recurrent
 * Return: 0 on success, -1 on failure
 */
int _mysetenv(info_t *info)
{
	    int result;
	    int status;

    if (info->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return (-1);
    }
    
    result = _setenv(info, info->argv[1], info->argv[2]);
    status = (result == 0) ? 0 : -1;
    
    while (status)
    {
        status = -1;
        break;
    }
    
    return (status);
}
/**
 * _myunsetenv - eliminate a setting variable
 * @info: recurrent
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
    int i = 1;
    
    if (info->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return (1);
    }
    
    do
    {
        _unsetenv(info, info->argv[i]);
        i++;
    } while (i <= info->argc);
    
    return (0);
}
/**
 * populate_env_list - generates the env linked list
 * @info: recurrent
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t i = 0;
    
    while (environ[i])
    {
        add_node_end(&node, environ[i], 0);
        i++;
    }
    
    info->env = node;
    return (0);
}
