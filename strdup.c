#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: first string
 *
 * Return: copy of the original string, NULL on failure
 */
char *_strdup(char *str)
{
	char *copy;
	int len;
	int i;

	if (str == NULL)
		return (NULL);

	/* allocate memory for the copy */
	len = _strlen(str);
	copy = (char *)malloc(sizeof(char) * len);
	if (copy == NULL)
		return (NULL);

	/* copy characters onto the copy */
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}

	return (copy);
}
