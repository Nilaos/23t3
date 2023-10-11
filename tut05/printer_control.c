#include <stdint.h>
#include <stdio.h>

// printerControl = 0 0 0 0 0 0 0 0
//                        ^ ^ ^ ^ ^
//                        | | | | |
//                        | | | | L [NO_INK]
//                        | | | L [COLOUR]
//                        | | L [SELECT_PRINT]
//                        | L [SELECT_SCAN]
//                        L [START]

// Printer flags as #defines
// Whether the printer is out of ink
#define NO_INK (0x1)  // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)  // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4)  // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)  // 0b 0000 1000
// Start print/scan
#define START (0x10)  // 0b 0001 0000

// The printer
uint8_t printerControl = 0;  // 0b 0000 0000

void checkInk(void);                // Question A
void replaceInk(void);              // Question B
void useColourAndSelectScan(void);  // Question C
void toggleMode(void);              // Question D
void start(void);                   // Question E

// Main function for testing
int main(void)
{
    printf("printerControl = 0x%02x\n", printerControl);
    checkInk();
    replaceInk();
    useColourAndSelectScan();
    toggleMode();
    start();
    printf("printerControl = 0x%02x\n", printerControl);
}

// Prints whether the printer has ink
void checkInk(void)
{
    // Check the NO_INK bit
    if (NO_INK & printerControl) {
        // printer is out of ink
    }
}

// Assume the user has replaced the ink
// So, we tell the printer there's ink again
void replaceInk(void)
{
    // Make NO_INK zero, keep all others
    // or operator
    // printerControl = printerControl ^ NO_INK;
    printerControl = printerControl & (~NO_INK)
}

// Select colour and scan mode
// Assume no mode has been selected yet
void useColourAndSelectScan(void)
{
    //
    uint8_t mask = COLOUR | SELECT_SCAN;
    printerControl |= mask;
}

// Toggle between print and scan mode
// Assume a mode has already been selected
void toggleMode(void)
{
    // TODO
    uint8_t mask = SELECT_PRINT | SELECT_SCAN;
    printerControl = printerControl ^ mask;
}

// Start printing/scanning and print relevant messages
void start(void)
{
    // Check that only 1 mode is selected
    // Double bang to boolean-ise our bitwise results
    // Has stdbool.h been introduced??
    int scanSelected = !!(printerControl & SELECT_SCAN);
    int printSelected = !!(printerControl & SELECT_PRINT);

    if (scanSelected == printSelected) {
        printf("Invalid mode\n");
        return;
    }

    if (printSelected) {
        if (printerControl & NO_INK) {
            printf("Trying to print, but no ink\n");
            return;
        }

        printf("Printing in %s\n", ((printerControl & COLOUR) ? "colour" : "black and white"));
    } else {
        printf("Scanning in %s\n", ((printerControl & COLOUR) ? "colour" : "black and white"));
    }

    // Start the task
    printerControl |= START;

    while (printerControl & START) {
        // Infinite loop until the printer unsets the start bit
        // In our code, this will never finish because we don't have a real printer on the other
        // side telling us when it's done
    }

    printf("Done!\n");
}
