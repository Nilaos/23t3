#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_run(void *data) {

    while (1) {
        printf("Hello from thread!\n");
        sleep(1);
    }

    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread,    // the pthread_t handle that will represent this thread
                   NULL,       // thread-attributes -- we usually just leave this NULL
                   thread_run, // the function that the thread should start executing
                   NULL        // data we want to pass to the thread -- this will be
                               // given in the `void *data` argument above
    );

    int c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}