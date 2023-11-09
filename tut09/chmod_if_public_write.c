
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++) {
        char *curr_file = argv[i];

        // todo: get permissions
        struct stat statbuf;
        int err = lstat(curr_file, &statbuf);
        if (err) {
            perror(curr_file);
            exit(1);
        }
        // todo: some error checking
        mode_t oldmode = statbuf.st_mode;

        if (oldmode & S_IWOTH) {
            // it is pub writable - change that
            mode_t newmode = oldmode & (~S_IWOTH);
            err = chmod(curr_file, newmode);
            if (err) {
                perror(curr_file);
                exit(1);
            }

            fprintf(stdout, "Changed mode of %s to 0%o", curr_file, newmode);
        } else {
            // not pub writable
            fprintf(stdout, "%s is not publically writable.", curr_file);
        }
    }
    return 0;
}
