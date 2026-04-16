#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFF_SIZE 1024
#define CHARS_TO_READ 1

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("You didn't give any parameters. Usage: %s filename\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    if (strncmp(argv[1], "--help", 6) == 0) {
        printf("Usage: %s [OPTIONS] [FILE]\nPuts file content to standard output.\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    const char* path = argv[1];
    const char* mode = "r";

    FILE *file = fopen(path, mode);
    if (file == NULL) {
        fprintf(stderr, "File %s cannot be opened. Error: %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buff[BUFF_SIZE];
    size_t read_count;

    while (1) {
        // buff filling with char sequence not trailed with 0
        read_count = fread(buff, CHARS_TO_READ, BUFF_SIZE, file);

        if (read_count == BUFF_SIZE) {
            // both printf and fwrite writes read_count characters but printf stops at \0
            //printf("%.*s", read_count, buff);
            fwrite(buff, 1, read_count, stdout);
        }
        else {
            if (ferror(file)) {
                fprintf(stderr, "Error while reading file %s: %s", path, strerror(errno));
                exit(EXIT_FAILURE);
            }
            // EOF reached
            // both printf and fwrite writes read_count characters but printf stops at \0
            //printf("%.*s", read_count, buff);
            fwrite(buff, 1, read_count, stdout);

            int ret = fclose(file);
            if (ret != 0) {
                fprintf(stderr, "Error while closing file %s: %s", path, strerror(errno));
                exit(EXIT_FAILURE);
            }
            break;
        }
    }
}
