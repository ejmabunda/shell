#include <unistd.h>

#include "shell.h"

/**
 * _puts - Prints a string.
 * @str: The string to print.
 *
 * Return: This function does not return any value.
 */
void _puts(const char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

