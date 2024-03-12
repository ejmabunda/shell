#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	pid_t child_pid;
	char *args[2];

	while (1)
	{
		_puts("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read == -1) /* End of file or error */
		{
			if (feof(stdin)) /* End of file */
			{
				_puts("\nGoodbye!\n");
				exit(EXIT_SUCCESS);
			}
			else /* Error */
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		
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
					/* Wait for the child process to complete */
					wait(NULL);
				}
			}
		        else
			{
				_puts(token);
				_puts(": No such file or directory\n");
			}
		}
	}
	free(line);

	return (0);
}
