#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * shell - simple shell
 *
 * Return: this function does not return any value
 */
void shell(void)
{
	char *line;
	size_t len;
	char **argv;
	pid_t child;

	while (1)
	{
		_puts("($) ");
		line = NULL;
		if (getline(&line, &len, stdin) == -1)
		{
			perror("getline error: ");
			continue;
		}

		/* remove newline character from input */
		rm_newline(line);

		if (_strcmp(line, "exit") == 0)
			exit(EXIT_SUCCESS);

		argv = _splitstr(line, " ");

		/* try to execute command in a child process */
		if (fork() == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve error: ");
				continue;
			}
			exit(0);
		}
		else
		{
			child = wait(NULL);
			child = child;
		}
	}
}
