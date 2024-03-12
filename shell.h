/* shell.h */
#ifndef SHELL_H
#define SHELL_H

/* Include necessary standard libraries */

/* Function prototypes */
/* Returns the length of a string */
int _strlen(const char *str);

/* Prints a string to stdout */
void _puts(const char *str);

/* Compares two strings. */
int _strcmp(const char *str1, const char *str2);

/* Tokenizes the input line, and tries to execute the first command. */
void tokenize(char *line);

#endif /* SHELL_H */
