#include "shell.h"

/**
* main - is a custom made shell
* Return: 0 on success, error on failure
*/

int main(void)
{
	char *buff = NULL;
	char *value, *pathname, **arv;
	ssize_t length = 0, size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while(length != EOF)
	{
		is_atty();
		len = getline(&buff, &size, stdin)
		_EOF(length, buff);
		arv = tokenizer(buff, " \n");
		if (!(arv || arv[0]))
			execute(arv);
		else
		{
			free(buff);
			f(arv);
		}
		else if (pathname)
		{
			free(arv[0]);
			arv[0] = pathname;
			execute(arv);
		}
		else if(!pathname)
			execute(arv);
	}
	free_list(head);
	freearv(arv);
	free(buff);
	return (0);
}

/**
* is_atty - check if it's the terminal
*/

void is_atty(void)
{
	if(is_atty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
* _EOF - handling end of file
* @len: return value of getline func
* @buff: buffer
*/

void _EOF(int length, char *buffer)
{
	(void)buffer;
	if (length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buf);
		}
		exit(0);
	}
}
/**
* signal_handler - checks if cntrl c is active
* @signal_num: int num
*/

void signal_handler(int signal_num)
{
	if (signal_num == SIGINT)
		_puts("\n#cisfun$ ");
}
