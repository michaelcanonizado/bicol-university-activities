#include <stdio.h>

int square(int num) {
    //
}

int main(void) {
    int integer;
    unsigned long long int result; 

    printf("Please enter a positive integer: ");
    scanf("%d", &integer);

    result = square(integer);

    printf("Factorial of %d is: %llu\n", integer, result);
}