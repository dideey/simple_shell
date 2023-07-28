#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <malloc.h>

#define EXEC_ERR ": not found\n"
#define CD_ERROR ": cd: can't cd to "
#define EXIT_ERROR ": exit: Illegal number: "
#define LOGIC_ERROR ": Syntax error: \""
#define LOGIC_ERRND "\" unexpected\n"
#define AND_OR_INPUT_ERR ": Syntax error: end of file unexpected\n"
#define SIZE_OF_CHARP 8
#define SIZE_OF_LIST_T 16
#define SIZE_OF_CHAR 1
#define BUFFER_SIZE 1024
/* environ built in variable */
extern char **environ;

/**
 *  * struct list_s - singly linked list
 *   * @data: string - (malloc'ed string)
 *    * @next: points to the next node
 *     * Description: singly linked list node structure
 *      */
typedef struct list_s
{
		char *data;
			struct list_s *next;

} list_t;
/* custom getline function */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* shell mode */
int non_interactive(size_t n, ssize_t input_count, char *input,
							int sc, char *e_ex, list_t *_environ);

/* command tokenizer */
int to_argv(char *str, char *e_ex, int sc, list_t *_environ);

/* exit <status> handler */
int exit_func(char **_argv, char *e_ex, int sc, char *copy,
					  char *input, list_t *_environ);

/* # handler */
int comment(char *input, char *e_ex, int sc, list_t *_environ);

/* ; handler */
int semi_colon(char *input, char *e_ex, int sc, list_t *_environ);

/* path handlers */
int locate_path(char **_argv, char *e_ex, int sc);
int search_path(char *path_dir, char **_argv, char *e_ex, int sc);
int _execute(char *path, char **_argv, char *e_ex, int sc);
int _access(char *path, char **_argv, char *e_ex, int sc);

/* error messages */
void exec_err_msg(char **_argv, char *e_ex, int sc);
void exit_err_msg(char **_argv, char *e_ex, int sc);
void setenv_usage_err_msg(char *e_ex);
void unsetenv_usage_err_msg(char *e_ex);
int and_or_err(char *e_ex, char *ao, int sc);
int and_or_input_err(char *e_ex, int sc);
int cd_err(char *e_ex, int sc, char *dir);
void print_error(char *err);
void error_num(int err);
void error_num(int num);

/* set and unset env */
char *_getenv(const char *name, list_t *_environ);
int _setenv(char *env, char *value, list_t **_environ);
char *to_env_var(const char *str1, const char *str2);
int _unsetenv(char *env, list_t **_environ);

/* && and || commands */
int order(char *token);
int get_operators(char *token, char *e_ex, int sc, char *input,
						  list_t *_environ);
int _identify(char **_argv, char *e_ex, int sc, char *copy,
					  char *input, list_t *_environ);
int and_or_check(char *token, char *e_ex, int sc, char *input,
						 list_t *_environ);
int and_first(char *token, char *e_ex, int sc, int i,
					  char *input, list_t *_environ);
int or_first(char *token, char *e_ex, int sc, int i,
					 char *input, list_t *_environ);
int check_error_comp(char **arr, char *token, int j,
							 char *e_ex, char *input, int sc, list_t *_environ);
int or_operator(char *token, char *e_ex, int sc, list_t *_environ);
int or_in_and(int i, char *token, char *e_ex, int sc,
					  int ret_val, char *input, list_t *_environ);
int run_and_logical(char *newstr, char type, char *e_ex, int sc,
							list_t *_environ);
int run_or_logical(char *newstr, char type, char *e_ex, int sc,
						   list_t *_environ);
int handle_error_com(char **arr, int n, char *e_ex, int sc);
int and_operator(char *token, char *e_ex, int sc, list_t *_environ);
int and_in_or(int i, char *token, char *e_ex, int sc, char *input,
					  list_t *_environ);
int check_error(char *input, char *e_ex, int sc, char *u_input,
						list_t *_environ);
int handle_error(char **arr, char *input, int j, char *u_input,
						 list_t *_environ, int n, int i, char *e_ex, int sc);
int and_or_user_input(char *input, char *e_ex, int sc, list_t *_environ);
int handle_error_com_ex(char **arr, int n, char *e_ex, int sc,
								char a, char *aa);

/* free functions */
void free_array(char **arr);
void free_list(list_t *head);
int error_and_free(char *str, char *e_ex, char *i_e, char **arr, int sc);
int return_and_free(char *str, char **arr, int ret_val);

/* custom functions */
int _putchar(char c);
void _print_str(char *);
void _print_int(int num);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strtok(char *const str, const char *const delim);
size_t _strcspn(const char *str1, const char *str2);
void *_realloc(void *ptr, size_t size);
size_t _strspn(const char *str, const char *set);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, char *src);
char *_strchr(const char *str, int c);
char *_strcat(char *dest, const char *src);
char *_strtok_r(char *str, const char *delim, char **saveptr);
char *_strpbrk(const char *s, const char *accept);
int _atoi(const char *str);
void str_rev(char *str, int length);
void to_str(int num, char *str);

/* create custom env functions */
list_t *add_node(list_t **head, char *data);
list_t *create_node(char *data);
void print_list(list_t *head);
list_t *get_environ(list_t *_environ);
list_t *delete_node(char *env, list_t **_environ);
char *_strdup(char *sstr);

/* cd */
int cd_command(char *path, char *e_ex, int sc, list_t *_environ);
#endif /*MAIN_H*/
