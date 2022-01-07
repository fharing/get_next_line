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
Go to the repository and compile the function with:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
For the sake of simplicty i added a main into the get_next_line.c file and a test text document(textfile).
If you want to test with another file just change line 103 in get_next_line.c to the new filename.
```code
open("FILENAME HERE",O_RDONLY);
```

__PLEASE NOTE THAT ALL PROJECTS AT 42 ARE WRITTEN ACCORDING TO THE NORMINETTE, WHICH PROVIDES US A WAY OF HOW TO WRITE CLEAN/READABLE CODE!__

```LINK
https://github.com/42School/norminette/blob/921b5e22d991591f385e1920f7e7ee5dcf71f3d5/pdf/en.norm.pdf
```
