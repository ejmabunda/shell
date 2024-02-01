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
	char **args;
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
		args = _split(line, ' ');
		if (fork() == 0)
		{
			execve(args[0], args, environ);
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

#include <string.h>

char **_split(char *str, char delim) {
    char **array = NULL;
    size_t num_elts = 0;
    int current_length = 0;
    int consumed = 0;
    size_t i;
    int due_to_end;

    for (i = 0; i < strlen(str); i++) {
        current_length++;
        due_to_end = 0;

        if ((str[i] == delim && i != (strlen(str) - 1)) ||
            (i == strlen(str) - 1 && (due_to_end = 1))) {
            array = realloc(array, (num_elts + 1) * sizeof(char *));
            array[num_elts] = calloc(current_length + 1, sizeof(char));
            memcpy(array[num_elts++], str + consumed, (due_to_end == 0 ? current_length - 1 : current_length));

            consumed += current_length;
            current_length = 0;
        }
    }
    /* terminate the array with NULL */
    array[num_elts] = NULL;

    return (array);
}
