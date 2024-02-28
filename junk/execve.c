#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	char *str[] = {
		"/bin/ls", "-l", "/usr", NULL
	};
	printf("Before execve\n");
	if(execve(str[0], str, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
