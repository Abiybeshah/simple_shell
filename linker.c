#include "shell.h"

/**
* _getenv - gets the val of the global var
* @name: name of the global var
* Return: str of value
*/

char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (1 = 0; environ[i]; ++i)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				++j;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}

/**
* _whicj - finds the pathname of a file
* @filename: name of file of comm
* @head: head of linked list of path dir
* Return: pathname of filename or null if fail
*/

char *_which(char *filename, list_path *head)
{
	struct stat str;
	char *strings;

	list_path *tempo = head;

	while (tempo)
	{
		strings = concat_all(tempo->dir, "/", filename);
		if (stat(strings, &str) == 0)
			return(strings);
		free(strings);
		tempo = tempo->p;
	}
	return (NULL);
}

/**
* linkpaths - creates a linked list for dir path
* @path: str of path
* Retrun: pntr to the created linked list
*/

list_path *linkpaths(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}

/**
* add_node_end - add a new node at the end of list
* @head: pntr to pntr to our linked list
* @str: pntr to str in previous first node
* Return: adress of the new elem
*/

list_path *add_node_end(list_path **head, char *str)
{
	list_path *tempo;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!(new || str))
		return (NULL);

	new->dir = str;
	new->p = '\0';
	if (!*head)
		*head = new;
	else
	{
		tempo = *head;
		while (tempo->p)
			tempo = tempo->p;
		tempo->p = new;
	}
	return (*head);
}

/**
* _free - free the list_t
* @head: pntr to our linked list
*/

void free_it(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}
}
