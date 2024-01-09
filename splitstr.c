#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _splitstr - splits a string
 * @str: string to split
 * @delim: character to split at
 *
 * Return: an array or string, NULL on failure or empty input
 */
char **_splitstr(char *str, char *delim)
{
	char **arr;
	char *copy, *token;
	int num_tok, index;
	
	if (str == NULL)
		return (NULL);

	/* make copy to preserve original string */
	copy = _strdup(str);
	if (copy == NULL)
		return (NULL);

	/* get number of tokens */
	num_tok = 0;
	token = strtok(copy, delim);
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		num_tok++;
		token = strtok(NULL, delim);
	}

	/* allocate memory for the array */
	arr = (char **)malloc(sizeof(char *) * num_tok);
	if (arr == NULL)
		return (NULL);

	/* copy tokens onto array */
	copy = _strdup(str);
	if (copy == NULL)
		return (NULL);

	token = strtok(copy, delim);
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
	free(copy);

	return (arr);
}
