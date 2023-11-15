// Program that prints all we want to now about now!
// But it's lazy so it calls other programs

#include <errno.h>
#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    pid_t process_ids[5];
    int status[5];

    // Note: All these arrays of strings MUST be null-terminated!
    // This is because we aren't passing in their size, so posix_spawn has to work it out
    char *date_args[] = {"/bin/date", "+%d-%m-%Y", NULL};
    char *time_args[] = {"/bin/date", "+%T", NULL};
    char *whoami_args[] = {"/usr/bin/whoami", NULL};
    char *hostname_args[] = {"/bin/hostname", "-f", NULL};
    char *realpath_args[] = {"/usr/bin/realpath", ".", NULL};

    posix_spawn(&process_ids[0], date_args[0], NULL, NULL, date_args, environ);
    waitpid(process_ids[0], &status[0], 0);

    posix_spawn(&process_ids[1], time_args[0], NULL, NULL, time_args, environ);
    waitpid(process_ids[1], &status[1], 0);

    posix_spawn(&process_ids[2], whoami_args[0], NULL, NULL, whoami_args, environ);
    waitpid(process_ids[2], &status[2], 0);

    posix_spawn(&process_ids[3], hostname_args[0], NULL, NULL, hostname_args, environ);
    waitpid(process_ids[3], &status[3], 0);

    posix_spawn(&process_ids[4], realpath_args[0], NULL, NULL, realpath_args, environ);
    waitpid(process_ids[4], &status[4], 0);

    return 0;
}
