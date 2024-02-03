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
		if (_strcmp(args[0], "exit") == 0)
			exit(EXIT_FAILURE);
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

/**
 * _split - splits a string into an array
 * @str: string
 * @delim: character
 *
 * Return: array
 */
char **_split(char *str, char delim)
{
	char **array = NULL;
	size_t num = 0;
	int len = 0;
	int consumed = 0;
	size_t i;
	int due_to_end;

	for (i = 0; i < strlen(str); i++)
	{
		len++;
		due_to_end = 0;
		if ((str[i] == delim && i != (strlen(str) - 1)) ||
		    (i == strlen(str) - 1 && (due_to_end == 1)))
		{
			array = realloc(array, (num + 1) * sizeof(char *));
			array[num] = calloc(len + 1, sizeof(char));
			memcpy(array[num++], str + consumed, (due_to_end == 0 ? len - 1 : len));
			consumed += len;
			len = 0;
		}
	}
	array[num] = NULL;
	return (array);
}
