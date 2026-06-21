# minishell

A small Unix shell written in C as part of the 42 curriculum. It recreates a focused subset of Bash behaviour: it reads input interactively, tokenizes and validates it, expands variables, builds commands, and executes them with proper process, file-descriptor, and signal handling.

Built collaboratively by [tmege](mailto:tmege@student.42barcelona.com) and [chgomez](mailto:chgomez@student.42barcelona.com).

---

## Highlights

- Execute commands through `PATH` with arguments and exit-status propagation.
- Support pipelines of arbitrary length and the `<`, `>`, `>>`, and `<<` redirections.
- Handle single quotes, double quotes, mixed quoting, `$VARIABLE`, and `$?` expansion.
- Implement the required built-ins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- Manage interactive and child-process behaviour for `Ctrl-C`, `Ctrl-\\`, and `Ctrl-D`.
- Use GNU Readline for command history and filename completion.

## Architecture

The command-processing pipeline is deliberately split into small, focused stages:

```text
input -> lexer -> syntax checker -> expander -> parser -> executor
```

```text
src/
├── lexer*.c             tokenization and quote-aware scanning
├── syntax_check.c       early validation of pipes and redirections
├── expander*.c          environment and exit-status expansion
├── parser*.c            token-to-command conversion
├── executor*.c          processes, PATH lookup, pipelines, and built-ins
├── redirections.c       file-descriptor redirection
├── heredoc*.c           heredoc collection and expansion rules
├── signals.c            interactive and execution signal handlers
└── builtins/            shell built-in implementations
```

The public data model is defined in [`inc/minishell.h`](inc/minishell.h). The project links against the local `Libft` library and GNU Readline.

---

## Requirements

- A C compiler (`cc`)
- `make`
- GNU Readline development files

On Debian or Ubuntu:

```bash
sudo apt-get install libreadline-dev
```

## Build and run

```bash
make
./minishell
```

Useful build targets:

```bash
make clean    # remove object files
make fclean   # remove object files and the executable
make re       # rebuild everything
```

Exit the shell with `exit` or `Ctrl-D`.

## Examples

```bash
echo "Hello, $USER"
ls -la | grep '\\.c$' | wc -l
cat < input.txt | grep minishell > matches.txt
export PROJECT=minishell
echo $PROJECT
cat << EOF
status: $?
EOF
```

Quoted heredoc delimiters suppress expansion:

```bash
cat << 'EOF'
$HOME is kept literal here
EOF
```

## Behaviour at a glance

| Area | Supported behaviour |
| --- | --- |
| Commands | External commands, arguments, and multi-stage pipelines |
| Redirections | Input, truncate output, append output, and heredocs |
| Quoting | Single quotes, double quotes, and quotes inside a word |
| Expansion | Environment variables and the previous command status (`$?`) |
| Built-ins | `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit` |
| Signals | Interactive `Ctrl-C`, execution-time `Ctrl-C`/`Ctrl-\\`, and EOF |

## Validation

The repository does not include an automated test script. The following checks are available locally:

```bash
make re
norminette inc src
```

After building, try representative commands such as the examples above, a syntax error (`echo >`), and an interrupt while a child process is running (`sleep 10`, then `Ctrl-C`).

## What this project demonstrates

- Translating an interactive language pipeline into maintainable C modules.
- Coordinating processes with `fork`, `execve`, `pipe`, `dup2`, and `waitpid`.
- Managing ownership, cleanup, and file descriptors across success and error paths.
- Designing shell semantics around quoting, expansion order, redirections, and exit statuses.
- Handling asynchronous signals without compromising the interactive prompt.

## References

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [POSIX Shell and Utilities](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)
- [GNU Readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Linux manual pages](https://man7.org/linux/man-pages/)

---

## Authors

- **tmege** — [tmege@student.42barcelona.com](mailto:tmege@student.42barcelona.com)
- **chgomez** — [chgomez@student.42barcelona.com](mailto:chgomez@student.42barcelona.com)
