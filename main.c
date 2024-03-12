#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "shell.h"

/**
 * main - Entry point
 *
 * Return: This function does not return any value.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		_puts("($) ");
		read = getline(&line, &len, stdin);
		if (read == -1) /* End of file or error */
		{
			if (feof(stdin)) /* End of file */
			{
				_puts("\n");
				exit(EXIT_SUCCESS);
			}
			else /* Error */
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		tokenize(line);
	}

	free(line);
	return (0);
}

/**
 * tokenize - Tokenize the input line, and try to execute
 * the first command.
 * @line: The input line.
 *
 * Return: This function does not return any value.
 */
void tokenize(char *line)
{
	pid_t child_pid;
	char *token, *args[2];

	/* Tokenize the input line */
	token = strtok(line, " \t\n");
	if (token != NULL)
	{
		/* Check if the token corresponds to a file */
		if (access(token, X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0) /* Child process */
			{
				/* Execute the command in the child process */
				args[0] = token;
				args[1] = NULL;
				execve(token, args, NULL);
				/* execve failed */
				_puts("Command not found: ");
				_puts(token);
				_puts("\n");
				exit(EXIT_FAILURE);
			}
			else /* Parent process */
			{
				wait(NULL); /* Wait for the child process to complete */
			}
		}
		else
		{
			_puts(token);
			_puts(": No such file or directory\n");
		}
	}
}
