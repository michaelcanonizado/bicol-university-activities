#include <stdio.h>

int multiply(int num1,int num2) {
    if (num2 == 1) {
        return num1;
    } else {
        return num1 + multiply(num1, num2-1);
    }
}

int main(void) {
    int integer1, integer2;
    unsigned long long int result; 

    printf("Please enter two positive integer: ");
    scanf("%d %d", &integer1, &integer2);

    result = multiply(integer1, integer2);

    printf("\n%d times %d is: %llu\n", integer1,integer2, result);
}