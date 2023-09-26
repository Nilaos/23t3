

// A simple program that will read 10 numbers into an array

#define N_SIZE 10
int numbers[N_SIZE] = {0};

#include <stdio.h>

int main(void)
{
    int i;

    i = 0;
    while (i < N_SIZE) {
        scanf("%d", &numbers[i]);
        i++;
    }
}