*This project has been created as part of the 42 curriculum by abezatog.*

![42 Istanbul](https://img.shields.io/badge/42-Istanbul-000000?style=flat-square&logo=42&logoColor=white)
![C](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c&logoColor=white)

## Description
The Get Next Line (GNL) project is a C programming task focused on writing a function that returns a single line read from a file descriptor. The function is designed to be called repeatedly in a loop to read a text file one line at a time until the end of the file is reached.

###  The Algorithm Workflow
The function breaks down into four steps:

1. **Safety Checks & Setup:** First, we make sure the file descriptor and `BUFFER_SIZE` are valid. If it's our first time reading from this file, we set our static variable to an empty string. This gives us a safe starting point so the program doesn't crash when we start adding text to it.
2. **Reading & Accumulating:** We start reading the file in chunks and glue these new chunks onto our static variable. We keep this loop going until we either spot a newline character (`\n`) or run out of text to read (EOF).
3. **Getting the Line:** Once we hit a newline, we stop reading. We slice out everything from the beginning up to that `\n`. This piece is the actual line we are going to return.
4. **Saving the Stash:** Because we read in chunks, we probably grabbed some extra characters *after* the newline. We save these leftovers back into our static variable. This way, we don't lose any data and are perfectly set up for the next time the function is called.

## Instructions

### Prerequisites
You need a C compiler (like `gcc` or `clang`) installed on your system.

To compile and use the `get_next_line` function in your projects, follow these steps:

1.  Clone the repository.
2.  Include the `get_next_line.h` header file in your C files.
3.  Compile your project with the source files using `cc` with the mandatory `-Wall -Wextra -Werror` flags.

```bash
git clone https://github.com/akinbezatoglu/get_next_line.git
cd get_next_line
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

## Resources

* read(2) manual
* [Static Variables in C](https://en.wikipedia.org/wiki/Static_variable)
* [C Programming Static Variables](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/compilers/c-programming/multi-file-projects/static-variables/)
* [File Descriptors (FD)](https://en.wikipedia.org/wiki/File_descriptor)
* [Handling a File by its Descriptor in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
* [Input-output system calls](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)

### AI Usage

AI has been used for the following purposes:

* Better understanding of the subject page
* Testing for edge cases
* Structuring and polishing the language used in this README documentation.s