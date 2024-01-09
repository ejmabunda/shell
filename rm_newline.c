#include "main.h"

/**
 * rm_newline - remove newline character
 * @str: string to modify
 *
 * Return: this function does not return any value
 */
void rm_newline(char *str)
{
	while (*str != '\n')
		str++;

	*str = '\0';
}
