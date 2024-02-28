#include "shell.h"

/**
* tokenize - makes a string into tokens into arrays
* @str: the str to be split
* @delim: the delimiter
* Return: array of pntrs to words
*/

char **tokenize(char *str, const char *delim)
{
	int i, j;
	char **array;
	char *token;
	char *copy;

	copy = malloc(_strlen(str) + 1);
	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		++i;
	}
	copy[i] = '\0';
	token = strtok(copy,delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	j = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = _realloc(array, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		array[i] = _strdup(token);
		++i;
		++j;
	}
	free(copy);
	return (array);
}

/**
* _free - frees the array of pntrs arv
* @arv: array of pntrs
*/

void free_it(char **arv)
{
	int i;

	for (i = 0; arv[i]; ++i)
		free(arv[i]);
	free(arv);
}
