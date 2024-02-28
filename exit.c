#include "shell.h"

/**
* ex_it -exits the shell with or w/t retrun status
* @arv: array of words of the entered line
*/

void ex_it(char **arv)
{
	int i, j;

	if (arv[1])
	{
		j = _atoi(arv[1]);
		if (j <= -1)
			n = 2;
		free_it(arv);
		exit(j);
	}
	for (i = 0; arv[i]; ++i)
		free(arv[i]);
	free(arv);
	exit(0);
}
