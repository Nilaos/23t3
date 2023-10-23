#include <stdint.h>
#include <stdio.h>

uint32_t six_middle_bits(uint32_t bits);

int main(int argc, char *argv[])
{
    uint32_t test = 0b10111101110011011011110000100101;  // 0xBDCDBC25
    // This test case should give 0b101101, or 0x2D
    printf("Six middle bits of %x are %x\n", test, six_middle_bits(test));
    return 0;
}

// Write a function, six_middle_bits, which given a uint32_t
// returns the middle six bits of it.
uint32_t six_middle_bits(uint32_t bits)
{
    // Step 1: Make the mask
    uint32_t mask;

    // Step 2: Align mask and value

    // Step 3: extract value

    // One line equivalent:

    // Moving mask example:

    // All of these operations produce equivalent, equal results
    // None modify the original variable
    return (uint32_t)result;
}
