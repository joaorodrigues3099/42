# Get Next Line

## Grading

**Score**: 125/100

## Project Overview

**Get Next Line** is a project developed as part of the 42 school curriculum. The goal of this project is to implement the function `get_next_line()` to read a file descriptor line by line, handling multiple lines efficiently while using dynamic memory allocation.

Here’s the updated **Features** section:

---

## Features

- **Efficient Memory Management**: The program reads files line by line, allocating memory only when necessary.
- **Handling Newlines**: The function handles newline characters (`\n`) properly, ensuring each line is read correctly.
- **Bonus**: Supports handling multiple file descriptors simultaneously.

---

## Key Functions

- **`get_next_line(int fd)`**: Reads the next line from a file descriptor.
- **`ft_strchr(const char *str, int c)`**: Locates the first occurrence of a character in a string.
- **`ft_lstnew(void *content)`**: Creates a new list element.
- **`ft_lstadd_back(t_list **lst, t_list *new)`**: Adds an element to the end of the list.
- **`ft_lstdel_safely(t_list **head, t_list *node, void (*del)(void *))`**: Safely deletes a list node.

## Compilation

To compile the project, create a `main.c` file with a `main()` function that calls `get_next_line()`. Then compile the project with the following command, passing the desired buffer size with the `-D BUFFER_SIZE=<value>` option:

### Regular Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<value> main.c get_next_line.c get_next_line_utils.c -o get_next_line
```

#### Example: Compiling with a buffer size of 4096:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 main.c get_next_line.c get_next_line_utils.c -o get_next_line
```

### Bonus Compilation

If you want to compile the bonus part of the project (which allows handling multiple file descriptors), use the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<value> main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line
```

#### Example: Compiling with a buffer size of 4096 and the bonus feature enabled:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line
```

## Usage

To use the `get_next_line()` function, here is an example `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
        return (1);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Notes

- This project utilizes linked lists to store content between reads and to handle buffer overflows.
- The program should be compiled using `cc` with appropriate flags for memory management and buffer handling.
