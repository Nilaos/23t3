

#include <stdio.h>

// A recursive function to calculate the factorial of 'number'
// - number: number to find the factorial of
int factorial(int number)
{
    if (number <= 0)
    {
        return 1;
    }

    return number * factorial(number - 1);
}

int main()
{
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);

    int f = factorial(num);
    printf("%d factorial is %d\n", num, f);
}