#include <stdio.h> /* stdin */
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * shell - simple shell
 * Return: this function does not return any value
 */
void shell(void)
{
	char *line;
	size_t len;
	char *argv[2];
	ssize_t read;

	len = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("($) ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		rm_newline(line);
		argv[0] = line;
		argv[1] = NULL;
		if (fork() == 0)
		{
			execve(line, argv, environ);
			perror("execve error: ");
			free(line);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	if (isatty(STDIN_FILENO))
		_puts("\n");
}
