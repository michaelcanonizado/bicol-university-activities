#include <stdio.h>

int power(int base,int exponent) {
    if (exponent == 1) {
        return base;
    } else {
        return base * power(base, exponent-1);
    }
}

int main(void) {
    int base, exponent;
    unsigned long long int result; 

    printf("Please enter the base: ");
    scanf("%d", &base);
    printf("Please enter the exponent: ");
    scanf("%d", &exponent);

    result = power(base, exponent);

    printf("\n%d to the power of %d is: %llu\n\n", base,exponent, result);
}