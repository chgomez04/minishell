*This project was created as part of the 42 curriculum by tmege and chgomez.*

# minishell

## Overview

`minishell` is a Unix shell implementation written in C.

The project recreates a focused subset of Bash behavior, including interactive input, lexical analysis, syntax validation, environment expansion, command parsing, process execution, pipes, redirections, built-ins and signal handling.

The goal of the project is to understand how a shell works internally and how Unix processes, file descriptors, signals and environment variables interact.

Built collaboratively by `tmege` and `chgomez`.

## Description

`minishell` reads a command line from the user, analyzes it, expands variables, builds an internal command representation and executes the result.

The command-processing flow is divided into clear stages:

```text
input -> lexer -> syntax checker -> expander -> parser -> executor
```

The project focuses on:

- Interactive command-line input.
- Tokenization and quote-aware parsing.
- Syntax validation for pipes and redirections.
- Environment variable expansion.
- Built-in command implementation.
- Execution of external commands through `PATH`.
- Process creation with `fork()`.
- Program execution with `execve()`.
- File descriptor redirection with `dup2()`.
- Pipeline execution with `pipe()`.
- Signal handling in interactive and child-process contexts.
- Memory management and cleanup.

## Features

- Interactive prompt using GNU Readline.
- Command history support.
- External command execution.
- `PATH` resolution.
- Multi-command pipelines.
- Input redirection with `<`.
- Output redirection with `>`.
- Append redirection with `>>`.
- Heredoc support with `<<`.
- Single quote handling.
- Double quote handling.
- Environment variable expansion with `$VARIABLE`.
- Previous exit status expansion with `$?`.
- Built-in command execution.
- Exit status propagation.
- Interactive signal handling.
- Clean resource management.

## Supported Built-ins

| Built-in | Description |
| --- | --- |
| `echo` | Prints arguments to standard output |
| `cd` | Changes the current working directory |
| `pwd` | Prints the current working directory |
| `export` | Adds or updates environment variables |
| `unset` | Removes environment variables |
| `env` | Prints the current environment |
| `exit` | Exits the shell |

## Supported Operators

| Operator | Description |
| --- | --- |
| `|` | Connects commands through a pipeline |
| `<` | Redirects input from a file |
| `>` | Redirects output to a file, truncating it |
| `>>` | Redirects output to a file, appending to it |
| `<<` | Starts a heredoc input block |

## Signal Behavior

| Input | Behavior |
| --- | --- |
| `Ctrl-C` | Interrupts the current prompt or running child process |
| `Ctrl-\` | Managed differently depending on interactive or execution context |
| `Ctrl-D` | Exits the shell when entered on an empty prompt |

Signal behavior is handled differently depending on whether the shell is waiting for input or executing a child process.

## Technologies

- C language
- Unix system calls
- GNU Readline
- File descriptors
- Pipes
- Processes
- Signals
- Environment variables
- Dynamic memory management
- Makefile
- Compilation with `cc`
- Flags: `-Wall -Wextra -Werror`

## Project Structure

```text
.
├── Makefile
├── README.md
├── es.subject.pdf
├── Libft/
├── get_next_line/
├── inc/
│   └── minishell.h
└── src/
    ├── builtins/
    ├── executor*.c
    ├── expander*.c
    ├── heredoc*.c
    ├── lexer*.c
    ├── parser*.c
    ├── redirections.c
    ├── signals.c
    ├── syntax_check.c
    └── main source files
```

## Requirements

Install GNU Readline development files before compiling.

On Debian or Ubuntu:

```bash
sudo apt-get install libreadline-dev
```

You also need:

- `cc`
- `make`
- A Unix-like environment

## How to Compile

Compile the project:

```bash
make
```

This generates the executable:

```text
minishell
```

Remove object files:

```bash
make clean
```

Remove object files and the executable:

```bash
make fclean
```

Rebuild the project:

```bash
make re
```

## How to Run

Start the shell:

```bash
./minishell
```

Exit the shell:

```bash
exit
```

or press:

```text
Ctrl-D
```

## Usage Examples

Run a simple command:

```bash
echo "Hello, minishell"
```

Use an environment variable:

```bash
echo $USER
```

Check the previous exit status:

```bash
echo $?
```

Run a pipeline:

```bash
ls -la | grep ".c" | wc -l
```

Use input and output redirection:

```bash
cat < input.txt > output.txt
```

Append output to a file:

```bash
echo "new line" >> output.txt
```

Use a heredoc:

```bash
cat << EOF
hello
world
EOF
```

Use a quoted heredoc delimiter to avoid expansion:

```bash
cat << 'EOF'
$HOME is kept literal here
EOF
```

## Behavior at a Glance

| Area | Supported behavior |
| --- | --- |
| Commands | External commands with arguments |
| Pipelines | Multi-stage pipelines |
| Redirections | `<`, `>`, `>>`, `<<` |
| Quoting | Single quotes, double quotes and mixed quoting |
| Expansion | Environment variables and `$?` |
| Built-ins | `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit` |
| Signals | Interactive and execution-time signal behavior |

## Testing

Rebuild the project:

```bash
make re
```

Run Norminette if available:

```bash
norminette inc src Libft get_next_line
```

Run the shell:

```bash
./minishell
```

Suggested manual tests:

```bash
echo hello
echo "$USER"
echo '$USER'
pwd
cd ..
pwd
export TEST=minishell
echo $TEST
unset TEST
env
ls -la | grep ".c" | wc -l
cat < input.txt | grep minishell > output.txt
echo $?
```

Suggested syntax-error tests:

```bash
|
echo >
cat <
echo hello |
```

Suggested signal tests:

```bash
sleep 10
```

Then press `Ctrl-C`.

## Implementation Highlights

- The lexer converts user input into tokens while respecting quotes.
- The syntax checker validates pipe and redirection placement before execution.
- The expander resolves environment variables and `$?`.
- The parser transforms tokens into executable command structures.
- The executor handles built-ins, external commands, pipes and process creation.
- Redirection logic manages input, output, append and heredoc file descriptors.
- Signal handling is adapted for interactive mode and child-process execution.
- Environment data is stored and updated internally for built-ins such as `export`, `unset` and `cd`.
- Cleanup logic releases allocated memory and closes file descriptors across success and error paths.

## What I Learned

- How Unix shells parse and execute commands.
- How to build a lexer and parser for command-line input.
- How quoting rules affect tokenization and expansion.
- How environment variable expansion works.
- How to implement built-in shell commands.
- How to create processes with `fork()`.
- How to execute programs with `execve()`.
- How to connect commands with `pipe()`.
- How to redirect input and output with `dup2()`.
- How to manage signals in interactive programs.
- How to organize a larger C project with multiple modules.
- How to work collaboratively on a complex C codebase.

## Resources

- 42 minishell subject
- Bash Reference Manual
- POSIX Shell and Utilities documentation
- GNU Readline documentation
- Linux manual pages:
  - `man fork`
  - `man execve`
  - `man pipe`
  - `man dup2`
  - `man waitpid`
  - `man signal`
  - `man readline`

## Notes

This project follows the constraints and style expected in the 42 curriculum.  
The implementation is intentionally written in C and focuses on shell internals, parsing, process management, file descriptors, signals and environment handling.

This is not intended to be a full Bash replacement. It implements the subset of behavior required by the project subject.

## Author

Christian Gómez (`chgomez`)  
Junior Software Developer in training at 42 Barcelona  
GitHub: [github.com/chgomez04](https://github.com/chgomez04)
