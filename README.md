# Cat

A simple program to output file contents to standard output. Inspired by cat from GNU Coreutils. \
Currently, it only supports files consist of ASCII characters (not extended ASCII).

## Compilation

Clone the repo if not already: `git clone https://github.com/m-enes/cat.git`. \
Go into repo directory: `cd cat`. \
Create bin directory: `mkdir bin`. \
Compile the source code: `gcc -Wall -Wpedantic cat.c -o bin/cat`. \
Go into bin directory: `cd bin`. \
Create or copy a text file into the bin directory. \
Run the program: `./cat <filename>`, replace <filename> with the name of the file you want to read in the bin directory.
