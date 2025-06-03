# GET_NEXT_LINE
This project is about creating a function that reads a file one line at a time. It handles reading with buffers, managing static memory, and assembling lines accross multiple read calls.

## Technologies used
- Language
	- C
- Tools
	- Makefile
- Norm
	- [42 norminette](https://github.com/42school/norminette)

## What I learned
- Buffer management and string concatenation
- Handle memory leaks and freeing unused memory
- Manage multiple file descriptors

## How to run
```make```
OR to manage multiple file descriptors at the same time
```make bonus```

### Example usage
```C
#include "get_next_line.h"
int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line = get_next_line(fd);
} ```
