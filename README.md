## About

The purpose of this project is to code a function that returns a line read from a file descriptor.

Repeated calls (e.g., using a loop) of the get_next_line() function let
you read the text file pointed to by the file descriptor, one line at a time.
The function return the line that was read.
If there is nothing else to read or if an error occurred, it return NULL.
It can also read from standard input.
Please note that the returned line include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

Because you will have to read files in get_next_line(), add this option to your compiler call:
```bash
-D BUFFER_SIZE=n
```
It will define the buffer size for read().

Forbidden:
- You are not allowed to use your libft in this project.
- lseek() is forbidden.
- Global variables are forbidden.

| Program name | - |
| :--- | :--- |
| Protoype| char *get_next_line(int fd) |
| Parameters| fd: The file descriptor to read from |
| External functions | read, malloc, free |

## How to use

Clone the repository:
```bash
https://github.com/fharing/get_next_line.git
```
Go to the repository and compile the function with a main.c file:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```