#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;

	while (1)
	{
		_puts("#cisfun$ ");
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
		/* Tokenize the input line */
		token = strtok(line, " \t\n");
		
		if (line[0] != '\n')
		{
			_puts(line);
			_puts(": No such file or directory\n");
		}
	}
	free(line);

	return (0);
}
