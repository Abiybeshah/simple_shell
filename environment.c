#include "shell.h"

/**
* envn - prints the current envn
* @arv: array of args
*/

void env(char __attribute__ ((unused)) **arv)
{
	int i;

	for (i = 0; environ[i]; ++i)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
* _setenv - init a new envn variable or modify an existing one
* @arv: array of entered words
*/

void _setenv(char **arv)
{
	int i,j,k;

	if (!(arv[1] || arv[2]))
	{
		perror (_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; ++i)
	{
		j = 0;
		
		if (arv[1][j] == environ[i][j])
		{
			while (arv[i][j])
			{
				if (arv[1][j] != environ[i][j])
					break;
				++j;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;

				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					++k;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = concat_all(arv[1], "=", arv[2]);
		environ(i + 1) = '\0';
	}
}

/**
* _unsetenv - remove an envnmt var
* @arv: array of entered words
*/

void _unsetenv(char **arv)
{
	int i,j;

	if (!arv[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; ++i)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;
				++j;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					++i;
				}
				return;
			}
		}
	}
}
