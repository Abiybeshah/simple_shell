#include "shell.h"

/**
* execute - executes a comm
* @arv: array of args
*/

void execute(char **arv)
{
	int pid;
	int status;

	if (!(arv || arv[0]))
		return;

	pid = fork();
	if (pid == -1)
		perror(_getenv("_"));
	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
* _realloc - reallocates mem block
* @ptr: previous pointer
* @old size: old size of previous pntr
* @newsize: new size of new pntr
* Return: new resized pntr
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free (ptr);
		return (NULL);
	}
	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; ++i)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; ++i)
			new[i] = old[i];
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; ++i)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
* _free - frees the array of pntrs arv
* @arv: array of pntrs
*/

void free_arv(char **arv)
{
	int i;

	for (i = 0; arv[i]; ++i)
		free(arv[i]);
	free(arv);
}
