
// FILE*
// stdin

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write to file
// File is command line arg
// read from stdin
int main(int argc, char const* argv[])
{
    if (argc < 2) {
        printf("Usage: ./write_line <filename>\n");
        exit(EXIT_SUCCESS);
    }

    char line[1024];
    FILE* filep = fopen(argv[1], "w");
    if (filep == NULL) {
        perror(argv[1]);
        printf("%s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fgets(line, 1024, stdin) == NULL) {
        // handle this!
    }

    fputs(line, filep);

    fclose(filep);

    return EXIT_SUCCESS;
}
