
# DevSecOps Command Console

DevSecOps Command Console is a Linux-based custom shell designed to
provide a unified interface for DevOps and system administration tasks.

## Week 1 Features

- Interactive REPL loop
- Custom devshell prompt
- Makefile-based build
- Linux development environment
- Git repository
- GitHub repository

## Build

make

## Run

make run

## Current Week 1 Commands

- exit

## Future Features

- Command parsing
- Process management
- File management
- Backup and restore
- System monitoring
- IPC
- Scheduling
- Multithreading
- Security validation
- Audit logging

## Week 2 Features

- Dynamic command input
- Memory allocation using malloc()
- Automatic buffer expansion using realloc()
- Proper memory cleanup using free()
- Modular input handling using input.h and input.c

## Week 3 Features

- Command parsing using strtok()
- Dynamic argv[] construction
- Modular parser implementation
- Ready for process execution with execvp()

## Week 4 Features

- Process creation using fork()
- Command execution using execvp()
- Parent-child synchronization using waitpid()
- Error handling using perror()
- Execution of real Linux commands

## Week 5 Features

- Built-in command support
- `cd` command
- `pwd` command
- `help` command
- `clear` command
- `exit` command
- Environment variable support using `getenv()`
- Separation of built-in and external commands
- Built-in commands execute inside the shell
- External commands execute using `fork()` and `execvp()`

## Week 6 Features

- Signal handling
- SIGINT support
- SIGCHLD support
- Shell survives Ctrl+C
- Child process cleanup using waitpid()
- Zombie process prevention
