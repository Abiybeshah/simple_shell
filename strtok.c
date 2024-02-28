#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i;
	char *str;
	size_t n = 32;
	char *buffer;
	size_t string;

	buffer = malloc(sizeof(char) * n);
	printf(">");
	string = getline(&buffer, &n, stdin);
	str = strtok(buffer, " ");
	while (str != NULL)
	{
	printf("%s\n",str);
	str = strtok(NULL, " ");
	}
	free (buffer);
	return (0);
}
