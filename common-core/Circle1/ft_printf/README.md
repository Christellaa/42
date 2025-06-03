# FT_PRINTF
This project is a re-implementation of the standard C printf function. It handles variable arguments and supports formatted output with these specifiers: `%c, %s, %p, %d, %i, %u, %x, %X, %%`.

## Technologies used
- Language
	- C
- Tools
	- Makefile
- Norm
	- [42 norminette](https://github.com/42school/norminette)

## What I learned
- Use variadic functions
- Format and convert different data types

## How to run
```make```

### Example usage
```C
#include "ft_printf.h"
int main(void)
{
	ft_printf("Hello %s! Number: %d\n", "world", 26);
} ```
