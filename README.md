# Simple Shell Project
A shell is a program that exposes an operating system's services to a human user or other programs, according to Wikipedia. In this joint project between Makoena Letseku and Junior Mabunda, will write a custom UNIX command-line interpreter with the following features:
- Displays a prompt, and waits for the command
- The prompt is displayed again, after each command execution
- Simple shell, no advanced features
- Commands are made of only one word. No arguments.
- If an executable cannot be found, an error message is displayed and the user is prompted again.
- Handles errors, and the `EOF` "end of file" condition (`Ctrl+D`)

## Compilation
The shell was tested with the following command:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```