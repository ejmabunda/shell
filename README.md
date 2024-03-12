# Simple Shell Project

## Overview

This is a simple UNIX command line interpreter, a basic shell designed to handle single-word commands. The goal is to create a minimalist shell.

## Usage

To run the shell, first compile it with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Then, run it with the following command:

```
./hsh
```

## Features

1. **Command Prompt:**
   - The shell displays a prompt and waits for the user to input a command.
   - The prompt is shown again after each command execution.

2. **Command Execution:**
   - Processes simple, single-word command lines.
   - Executes the command using `execve`.

3. **Error Handling:**
   - If an executable cannot be found, the shell prints an error message and prompts the user again.
   - Handles other potential errors during execution.

4. **End of File Condition:**
   - The shell gracefully handles the "end of file" condition (Ctrl+D).