// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void)
{
main__row_loop_start:
    int i = 1;
main__row_loop_cond:
    // while (i <= 10)
    if (i > 10)
        goto main__row_loop_end;
// for (int i = 1; i <= 10; i++)
// {
// while (j < i)
main__col_loop_start:
    int j = 0;
main__col_loop_cond:
    if (j >= i)
        goto main__col_loop_end;
    // {
    // for (int j = 0; j < i; j++) {
    printf("*");
    j++;
    goto main__col_loop_cond;
    // }
main__col_loop_end:
    printf("\n");
    i++;
    goto main__row_loop_cond;
    // }
main__row_loop_end:
    return 0;
}