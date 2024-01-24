# pipex - Custom Shell Command Pipeline Implementation
Welcome to my pipex repository! This project features my implementation of a simplified shell command pipeline in C, inspired by the UNIX shell's pipe (|) operator.
The goal is to create a program that emulates the behavior of a shell pipeline, taking two commands and two file arguments.

## Overview
## Files
pipex.h: Header file containing function prototypes, necessary includes, and any macros or constants.
pipex.c: Main program file containing the main function and the core logic for executing the command pipeline.
libft: A custom library containing useful utility functions (such as string manipulation and memory allocation).
## Usage
## Compilation
Compile the program using the provided Makefile:

```
make
```
This will generate the pipex executable.

Execution
Run the program by providing two commands and two file arguments:

```
./pipex file1 cmd1 cmd2 file2
```
file1: Input file whose content will be used as the input for the first command.
cmd1: The first command in the pipeline.
cmd2: The second command in the pipeline.
file2: Output file where the result of the pipeline will be stored.

## Example
```
./pipex infile "ls -l" "grep foo" outfile
```
This example runs the command pipeline equivalent to ls -l | grep foo and stores the result in outfile.

## Implementation Details
The pipex program works by creating a process pipeline between the two specified commands. It uses file descriptors and the fork, pipe, dup2, and execve system calls to set up the pipeline and execute the commands.

Child and Parent Processes
The pipex program utilizes the fork system call to create a child process. The child process is responsible for executing the first command in the pipeline (cmd1). It reads from the input file (file1) and writes the output to a pipe.

The parent process, on the other hand, continues its execution after the fork call. It is responsible for executing the second command in the pipeline (cmd2). The parent process reads from the pipe and writes the output to the output file (file2).

This coordination allows the two commands to execute in parallel, with the output of the first command becoming the input of the second command. The use of a pipe (pipefd) facilitates communication between the child and parent processes.

## Error Handling
The implementation includes error handling to check for any failures during the process creation and execution.

## Note
This pipex implementation is designed for educational purposes and provides a simplified version of a shell command pipeline. Contributions and feedback are welcome to enhance and refine the implementation for different use cases.

Happy piping with pipex!
