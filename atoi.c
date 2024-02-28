#include "shell.h"

/**
* _atoi - converts a string into an int
* @s: pointer to a str
* Return: the int
*/

int _atoi(char *s)
{
	int i, integ_er, sign = 1;

	i = 0;
	integ_er = 0;

	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
			sign = sign * (-1);
		++i;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integ_er = (integ_er * 10) + (sign * (s[i] - '0'));
		++i;
	}
	return (integ_er);
}
