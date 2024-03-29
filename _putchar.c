#include "shell.h"
/**
* _putchar - writes the char c to stdout
* @c: the char to print
* Return: on success 1,on error -1 is returned
*/

int _putchar(char c)
{
	return (write(1, &c, 1);
}
/**
* _puts - prints a string
* @str: pointer to string
*/

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		++i;
	}
}

