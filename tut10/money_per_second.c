#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>

int money = 0;
atomic_int atomic_money = 0;

void *add_5000_to_counter(void *data)
{
    pthread_mutex_t *lock = data;
    for (int i = 0; i < 5000; i++) {
        // sleep for 1 nanosecond
        nanosleep(&(struct timespec){.tv_nsec = 1}, NULL);
        money = money + 1;
    }

    return NULL;
}

void *sub_1000_to_counter(void *data)
{
    pthread_mutex_t *lock = data;
    for (int i = 0; i < 1000; i++) {
        atomic_money--;
        // sleep for 1 nanosecond
        nanosleep(&(struct timespec){.tv_nsec = 1}, NULL);

        // decrement the global total by 1
        money = money - 1;
    }

    return NULL;
}

int main(void)
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_t thread3;
    pthread_create(&thread3, NULL, sub_1000_to_counter, NULL);

    pthread_t thread4;
    pthread_create(&thread4, NULL, sub_1000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    // if program works correctly, should print 10000
    printf("Final totals: %d, %d, %d\n", money, atomic_money);
}