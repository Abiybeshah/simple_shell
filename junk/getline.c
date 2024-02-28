#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	size_t n = 32;
	char *buffer;
	size_t str;

	buffer = (char *)malloc(n * sizeof(char));
	if (buffer == NULL)
	{
		perror("unable to allocate buffer");
		exit(1);
	}
	printf("$");
	str = getline(&buffer, &n, stdin);

	printf("%ld characters were read\n", str);
	printf("and you typed this '%s'\n", buffer);

	free (buffer);
	return (0);
}
