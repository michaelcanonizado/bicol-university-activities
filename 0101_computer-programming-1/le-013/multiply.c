#include <stdio.h>

int multiply(int num) {
    
}

int main(void) {
    int integer;
    unsigned long long int result; 

    printf("Please enter a positive integer: ");
    scanf("%d", &integer);

    result = multiply(integer);

    printf("Square of %d is: %llu\n", integer, result);
}