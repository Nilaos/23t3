// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void)
{
row_loop_init:
    int i = 1;
row_loop_cond:
    // for (int i = 1; i <= 10; i++) {
    // while (i <= 10) {
    if (i > 10)
        goto row_loop_end;

    for (int j = 0; j < i; j++) {
        printf("*");
    }
    printf("\n");

row_loop_iter:
    i++;
    goto row_loop_cond;
row_loop_end:
    // }
    return 0;
}
