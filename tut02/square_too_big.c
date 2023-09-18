#include <stdio.h>

int main(void)
{
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

main__if_x_gt_46340:
    if (x < 46340)
        goto main__x_lt_46340;
    // if (x >= 46340) {
    // If we have reached this, then x is too big
    printf("square too big for 32 bits\n");
    // } else {
main__x_lt_46340:
    y = x * x;
    printf("%d\n", y);
    // }

main__epilogue:
    return 0;
}