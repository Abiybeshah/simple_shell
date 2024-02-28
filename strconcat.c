#include "shell.h"

/**
* concat_all - concats 3 strings in a new mem
* @name: first str
* @sep: sec string
* @value: third str
* Return: pointer to the new str
*/

char *concat_all(char *first, char *sec, char *thris)
{
	char *result;
	int sl, s2, s3, i, k;

	s1 = _strlen(name);
	s2 = _strlen(name);
	s3 = _strlen(name);

	result  = malloc(s1 + s2 + s3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; first[i]; ++i)
		result[i] = first[i];
	k = i;

	for (i = 0; sec; ++i)
		result[k + i] = sec[i];
	k = k + i;

	for (i = 0; thris[i]; i++)
		result[k + i] = thris[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
* _strlen - it gives the length of a str
* @s: pointer to the str
* Return: the len of str
*/

int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		++i;
	}
	return (i);
}
