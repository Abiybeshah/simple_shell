#include "shell.h"

/**
* _strdup - returns a pntr to a new mem space, wc
* contains a copy of the strn given as a param
* @str: pntr to a str
* Return: pntr to a str
*/

char *_strdup(char *str)
{
	int i, j;
	char *new;

	if (!str)
		return (NULL);

	for (j = 0; str[j] != '\0';)
		++j;
	
	new = malloc(sizeof(char) * j + 1);

	if (!new)
		return (NULL);

	for (i = 0; i < j; ++i)
		new[i] = str[i];

	new[j] = str[j];

	return (new);
}
