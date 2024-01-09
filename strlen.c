#include "main.h"

/**
 * _strlen - get string length
 * @str: string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;

	return (len);
}
