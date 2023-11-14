#include <stdio.h>

int main(void) {
    // Initialize Varablez. Use an unsigned long long int for total as the result of factorials can get quite big
    unsigned long long int total;
    int integer;

    // Prompt user
    printf("Factorial Calculator\n");
    printf("Enter a positive integer: ");
    scanf("%d", &integer);

    // We need to set the total's value to the first value of the integer times the second value. This allows it to not be kept inside the for loop. You can do this expression inside the for loop but you need to add a condition.
    total = integer * (integer-1);

    // Loop through the remaining values needed to be evaluated.
    // Set i's value to the third value of the integer, and start evaluating from there as the first 2 values has already been stored inside the total variable
    for(int i = integer-2; i >= 1; i--) {
        total = total * i;
    }

    // Output results
    printf("The factorial of %d is %llu\n", integer, total);

    return 1;
}