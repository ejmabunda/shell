#ifndef MAIN_H
#define MAIN_H

extern char **environ;

/* duplicates a string */
char *_strdup(char *str);

/* get string length */
int _strlen(char *str);

/* compares two strings */
int _strcmp(char *str1, char *str2);

/* print a character */
int _putchar(char c);

/* print a string */
void _puts(char *str);

/* print an integer */
void _putint(int n);

/* splits a string */
char **_splitstr(char *str, char *delim);

/* start the shell */
void shell(void);

/* remove newline character */
void rm_newline(char *str);

/* create an array and copy string tokens onto it */
char **_strtok_cpy(char *str, char *delim, int num_tok);

#endif
