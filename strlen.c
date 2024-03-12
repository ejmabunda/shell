#include <stdlib.h>
#include <stdio.h>

#include "shell.h"

/**
 * _strlen - Counts the number of characters in a string.
 * @str: The string to check.
 *
 * Return: The length of the string, an integer.
 */
int _strlen(const char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
