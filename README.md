*This project has been created as part of the 42 curriculum by ecantu-p*

# Description
### Get Next Line Function
Whether it's a file, stdin, or even later a network connection, you'll always 
need a way to read content line by line. It's time to start working on this 
function, which will be essential for future projects.

- Learn the concept of static variables in C programming.
- It should be done through writing a function named get_next_line that returns
 a line read from a file descriptor.

### Function structure

- The files to submit are: get_next_line.c, get_next_line_utils.c and 
get_next_line.h.
- Function Name: get_next_line.c
- Description: Write a function that returns a line read from a
file descriptor.
- Prototype as: `char *get_next_line(int fd);`
- Parameters: `fd`: the file descriptor to read from.
-     
    | Return value |  |
    | --- | --- |
    | Read Line: | correct behavior |
    | NULL: | there is nothing else to read, or an error occurred. |
- Allowed external functions: `read`, `malloc`, `free`

### Relevant aspects to consider

- The function should read one line at the time.
- The function should return the read line, otherwise `NULL`.
- The function should read from a file or form the standard input.
- Except for when the function reaches the file’s end, the function  must 
terminate each returned (displayed) line with \n.
- The header file must at least include the prototype of the get_next_line().
- Helper functions must be in the get_next_line_utils.c
- The functions should be compiled with and without the flag:
    
    `-D BUFFER_SIZE=n`
    
    where n is the buffer size in XXX. Initialize the buffer size. 
    
    eg. `cc -Wall -Wextra  -Werrror -D BUFFER_SIZE=42 <files>.c <file>.h`
    
- The `get_next_line( )` function main.c requires `read( )` function.
    - The written function exhibits undefined behavior if the associated file 
    with the file descriptor is modified after the last call, while read ( ) 
    has not reached the file’s end.
    - The written function exhibits undefined behavior when reading from a 
    binary file. It could implement logical way to handle this behavior if 
    need it.
- Return each line as it is read. Do not look to put the whole file in a buffer.
- Forbidden aspects:
    - The use of `libft` is prohibited.
    - The use of `lseek( )` is prohibited.
    - The use of  *Global variables* is prohibited.

# Instructions

1. To evaluate this project first you must have cloned its git repository. 
2. Verify Norminette against get_next_line.c, get_next_line_utils.c and 
get_next_line.h.
3. Comment out the main program to evaluate
4. Compile and verify either with: 
    1. `cc -Wall -Wextra  -Werrror <files>.c <file>.h`  
    or,
    2. `cc -Wall -Wextra  -Werrror -D BUFFER_SIZE=n <files>.c <file>.h`


# Resources

Define:

- File descriptor
    
    In Unix type systems, a **file descriptor** ( *fd* for short) is a small 
    positive integer used as reference to an open file in a process. A process 
    that is a currently running program. 
    
    However, from the operating system’s point of view, a file is not only a 
    text file as we might think of it as a user. A file can also be a directory 
    or even another type of input/output resource such as a keyboard, a screen, 
    [a pipe](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/) 
    or [a network socket](https://www.codequoi.com/en/sockets-and-network-programming-in-c/).
    
    By default, each process systematically inherits three open file 
    descriptors :
    
    | File Descriptor | Name | `<unistd.h>` | `<stdio.h>` |
    | --- | --- | --- | --- |
    | `0` | Standard Input | `STDIN_FILENO` | `stdin` |
    | `1` | Standard Output | `STDOUT_FILENO` | `stdout` |
    | `2` | Standard Error | `STDERR_FILENO` | `stderr` |
    
    But why use file descriptors as identifiers? An integer is much 
    simpler to process for a computer than a long path string to a file. What’s 
    more, the reference to a file must contain much more than its location: it 
    must also include its permissions, access mode, size, etc… 
    And wouldn’t it be wasteful to keep several entire references to the same 
    file if several processes opened it?
    
    https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
    
- NULL
       
    Data written to a **null** or **zero** special file is discarded.
    
    Reads from the **null** special file always return end of file (i.e., 
    [***read**](https://linux.die.net/man/2/read)(2)* returns 0), whereas reads from **zero** always return bytes containing zero (\0 characters).
    
    https://linux.die.net/man/4/null
    
- `read ( )`
    
    ```c
    #include <unistd.h>
    ssize_t read(int fd, void *buf, size_t count);
    ```
    
    **Description**
    
    **read**() attempts to read up to *count* bytes from file descriptor *fd* 
    into the buffer starting at *buf*.
    
    On files that support seeking, the read operation commences at the current 
    file offset, and the file offset is incremented by the number of bytes read. 
    If the current file offset is at or past the end of file, no bytes are read, 
    and **read**() returns zero.
    
    If *count* is zero, **read**() *may* detect the errors described below. 
    In the absence of any errors, or if **read**() does not check for errors, 
    a **read**() with a *count* of 0 returns zero and has no other effects.
    
    **Return Value**
    
    On success, the number of bytes read is returned (zero indicates end of 
    file), and the file position is advanced by this number. It is not an error 
    if this number is smaller than the number of bytes requested; this may 
    happen for example because fewer bytes are actually available right now 
    (maybe because we were close to end-of-file, or because we are reading from 
    a pipe, or from a terminal), or because **read**() was interrupted by a 
    signal. On error, -1 is returned, and *errno* is set appropriately. In 
    this case it is left unspecified whether the file position (if any) changes.
    
    https://linux.die.net/man/2/read
    
- Standard Input
    
    A process uses to take input from a source, by default the keyboard. 
    
    https://stackoverflow.com/questions/5256599/what-are-file-descriptors-explained-in-simple-terms
    

- Static Variable in C
 https://www.cs.toronto.edu/~krueger/csc209h/lectures/Week6-misc-4.pdf

- BUFFER_SIZE flag in cc.  
    This is not a flag. The flag is -D. **gcc -D** defines a macro to be used 
    by the preprocessor. In our case, the buffer size to use.

- Other:

    https://en.wikipedia.org/wiki/Escape_sequences_in_C

    https://gist.github.com/JBlond/2fea43a3049b38287e5e9cefc87b2124

- AI  
    AI tools were utilized to debug a recurring segmentation fault in the static 
    linked list. The specific solution and technical approach are detailed in 
    the bonus section.

# Additional Sections

## Chosen Algorithm

![Chosen Algorithm](https://raw.githubusercontent.com/erickCantu/gnl/refs/heads/main/algorithm_final.png)

## Bonus

- Develop get_next_line() using only one static variable
- Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you are reading from file descriptors 3, 4, and 5, you should be able
to read from a different file descriptor with each call, without losing track of the
reading state of each file descriptor or returning a line from a different one.
This means you should be able to call get_next_line() to read from fd 3, then fd
4, then fd 5, then again from fd 3, then fd 4, and so forth, without losing track of
the reading state for each file descriptor.
- Append the _bonus.[c\h] suffix to the bonus part files.
It means that, in addition to the mandatory part files, you will turn in the 3 following
files:
• get_next_line_bonus.c
• get_next_line_bonus.h
• get_next_line_utils_bonus.c

## Design
The bonus design considered using a static linked list as the base structure to 
store and retrieve read data. This turned out to be a wrong decision.

A linked list is a dynamically allocated data structure that should be able to 
mutate as necessary—its nodes should be created and freed as required. However, 
this is not the case with the get_next_line (gnl) function.

The "gnl" function requires a static variable to maintain its state between 
calls. When a linked list is used as a static variable, it leads to 
segmentation faults.

The reason for this is that when a node is freed, its memory location remains 
linked to the list because it's a static location. However, the node's content 
is actually freed, creating a mismatch. In other words, the node structure 
remains, but its content no longer exists.

This inconsistency leads to double-free errors and memory leaks, depending on 
how the linked list is passed through the function pipeline.

## Solution
Instead of linking the nodes, a linked structure vector was used. Each file 
descriptor had its own vector location, rather than being linked among them.
With this solution, the vector was static and able to maintain the data as 
required, and free it when necessary. This solution proved to fix the 
previously described segmentation and memory leak issues.
The core algorithm remains the same as in the mandatory section. 
