#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int16_t a, b, res;

    printf("Enter two integers: ");
    scanf("%hd %hd", &a, &b);

    res = a + b;

    printf("%hd + %hd = %hd\n", a, b, res);

    return 0;
}
