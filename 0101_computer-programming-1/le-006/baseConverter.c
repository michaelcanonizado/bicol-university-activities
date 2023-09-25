#include <stdio.h>

int main(void) {
    int number;

    printf("\nPlease input a number to see its various numerical representations: ");
    scanf("%d", &number);

    printf("\nDecimal: %d", number);
    printf("\nHexadecimal: %x", number);
    printf("\nOctal: %o", number);

    return 0;
}