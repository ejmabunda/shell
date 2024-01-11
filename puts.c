#include "main.h"
#include <stdlib.h>

/**
 * _puts - prints a string
 * @str: string to print
 *
 * Return: this function does not return any value
 */
void _puts(char *str)
{
	int index;

	if (str == NULL)
		return;

	index = 0;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
}
