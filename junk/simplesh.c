#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	size_t n = 32;
	size_t str;
	char *buffer;
	char *token = NULL;
	
	buffer = malloc(sizeof(char) * n);
	while (1)
	{
	printf(">");
	str = getline(&buffer, &n, stdin);
	token = buffer;
	printf("%s", token);
	}
	char tokenizer(token, 0);

	free (buffer);
	return (0);
}
char tokenizer(char *token, int n)
{
	int i = 0, j = 0;
	char *array;
	
	i = n;
	array = strtok(token, " ");
	while (token != NULL)
	{
		printf("%d\n", array[i]);
		token = strtok(NULL, " ");
	}
	return (array[i]);
}
