// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void)
{
// for (int i = 1; i <= 10; i++)
i_loop_init:
    int i = 1;
i_loop_cond:
    if (i > 10)
        goto i_loop_end;
    // while (i <= 10)
    // {

    for (int j = 0; j < i; j++)
    {
        printf("*");
    }
    printf("\n");
    i++;
i_loop_end:

    return 0;
}
