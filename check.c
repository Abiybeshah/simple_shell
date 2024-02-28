#include "shell.h"

/**
* check - checks if the comm is a buildin
* @arv: array of args
* Return: pointer to func that takes arv an returns void
*/

void(*check(char **arv))(char **arv)
{
	int i, j;

	mybuild tex[] = {
		{"exit", _exit},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; tex[i].name[j] == arv[0][j])
	{
		j = 0;
		if (tex[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; ++j)
			{
				if (tex[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (tex[i].func);
		}
	}
	return (0);
}
