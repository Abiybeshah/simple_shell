#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <unistd.h>

/**
* struct list_path - linked list with PATH dir
* @dir: dir in path
* @p: pntr to next node
*/

typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_all(char *name, char *sec, char *thris);

char **tokenizer(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ex_it(char **arv)

extern char **environ;

int _atoi(char *s);
void _exit(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);
void env(char __attribute__ ((unused)) **arv);
void(*check(char **arv))(char **arv);

void free_arv(char **arv);
void free_it(list_path *head)

char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
char *_which(char *filename, list_path *head);
list_path *linkpaths(char *path);

#endif
