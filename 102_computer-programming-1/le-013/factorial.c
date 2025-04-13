#include <stdio.h>

int factorial(int num) {
    if (num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main(void) {
    int integer;
    unsigned long long int result; 

    printf("Please enter a positive integer: ");
    scanf("%d", &integer);

    result = factorial(integer);

    printf("Factorial of %d is: %llu\n", integer, result);
}