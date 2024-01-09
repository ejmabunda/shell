#ifndef MAIN_H
#define MAIN_H

char *_strdup(char *str); /* duplicate a string */
int _strlen(char *str); /* get string length */
int _strcmp(char *str1, char *str2); /* compares two strings */
int _putchar(char c); /* print a character */
void _puts(char *str); /* print a string */
void _putint(int n); /* print an integer */
char **_splitstr(char *str, char *delim); /* splits a string */
void shell(); /* start the shell */
void rm_newline(char *str); /* remove newline character */

#endif
