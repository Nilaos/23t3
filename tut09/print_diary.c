

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    char *diary_name = ".diary";
    char diary_path[FILENAME_MAX] = {'\0'};

    // TODO: Create diary_path
    char *homepath = getenv("HOME");
    // printf("%s\n", homepath);
    // strncpy(diary_path, homepath, FILENAME_MAX);
    // strncat(diary_path, diary_name, FILENAME_MAX);

    snprintf(diary_path, FILENAME_MAX, "%s/%s", homepath, diary_name);

    FILE *diary_fp = fopen(diary_path, "a");
    if (diary_fp == NULL) {
        // perror("Unable to open ~/.diary");
        printf("Unable to open .diary: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char line[4096];
    fgets(line, 4096, stdin);

    fputs(line, diary_fp);

    fclose(diary_fp);

    return 0;
}
