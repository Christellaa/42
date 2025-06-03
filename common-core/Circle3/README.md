# MINISHELL
This project is a team project where we recreate a simplified version of the Bash shell. It supports these features:
- Signals:
	- `CTRL+C` to display a new prompt
	- `CTRL+D` to exit the shell
	- `CTRL+\` to do nothing
- Handle redirections:
	- `<` redirects input
	- `>` redirects output
	- `<< DELIMITER` reads the input until a line containing the delimiter is seen
	- `>>` redirects output in append mode
- Pipes (`|`): the output of each command is connected to the input of the next command
- Environment variables (eg: `$HOME`)
- `$?`: returns the exit status of the most recently executed foreground pipeline

It also has these built-ins:
- `echo` with option `-n`
- `cd` iwht only relative/absolute path
- `pwd` with no options
- `export` with no options
- `unset` with no options
- `env` with no options or arguments
- `exit` with no options

## Technologies used
- Language
	- C
- Tools
	- Makefile
- Norm
	- [42 norminette](https://github.com/42school/norminette)

## What I learned
- Parse and tokenize complex shell input
- Handle environment variables and `$?`
- Manage signals and terminal behavior
- Create child processes
- Redirect files

## How to run
```make```

### Example usage
```
make
./minishell
ls -la | grep .c > output.txt
echo $HOME
```
