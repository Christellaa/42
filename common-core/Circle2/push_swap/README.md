# PUSH_SWAP
This is an algorithmic project that requires sorting a stack of integers using a limited set of operations (sa, pb, ra, ...).
The goal is to write the most efficient program in terms of operation count.

## Information about V1 and V2
V1 uses Radix Sort algorithm
V2 uses the [Turk algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) and has a checker

## Technologies used
- Language
	- C
- Tools
	- Makefile
- Norm
	- [42 norminette](https://github.com/42school/norminette)

## What I learned
- Implement efficient sorting algorithms
- Use stacks and linked lists
- Optimize code for performance and constraints
- Parse arguments and error checking

## How to run
```make```
OR to check if the list is sorted
```make bonus```

### Example usage
```
make
./push_swap 3 2 5 1 4
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

make bonus
./checker 3 2 5 1 4
<add instruction followed by a newline>
<CTRL+D to end>

make && make bonus
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

```
