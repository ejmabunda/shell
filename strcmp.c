#include "main.h"

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if strings match, higher if str1 is higher,
 * lower if str1 is lower
 */
int _strcmp(char *str1, char *str2)
{
	/* find first non-matching character */
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	/* return difference */
	return (*str1 - *str2);
}
