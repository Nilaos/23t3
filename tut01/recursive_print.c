#include <stdio.h>







void print_array(int nums[], int len, int index)
{
    if (index >= len)
    {
        return;
    }
    printf("%d\n", nums[index]);
    print_array(nums, len, index + 1);


    // for (int i = 0; i < len; i++) {
    //     printf("%d\n", nums[i]);
    //
}

int main(void)
{
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    print_array(nums, 10, 0);

    return 0;
}