#include "main.h"
#include <stdlib.h> /* NULL, malloc, free */
#include <string.h> /* strtok */

/**
 * _strtok_cpy - copy strtok tokens on an array
 * @str: string to get tokens from
 * @delim: delimiter
 * @num_tok: number of tokens
 *
 * Return: array of strings, NULL on failure
 */
char **_strtok_cpy(char *str, char *delim, int num_tok)
{
	int index;
	char *token;
	char **arr;

	if (str == NULL)
		return (NULL);

	/* allocate memory for the array */
	arr = (char **)malloc(sizeof(char *) * num_tok);
	if (arr == NULL)
		return (NULL);

	/* copy tokens onto array */
	token = strtok(str, delim);
	if (token == NULL)
		return (NULL);

	index = 0;
	while (token != NULL)
	{
		arr[index] = _strdup(token);
		token = strtok(NULL, delim);
		index++;
	}

	free(token);

	return (arr);
}
