#include <stdio.h>
#include <math.h>

int main() {
    // Initialize the variables where inputs are Integers and products are Floats.
    int a, b, c;
    float A, P, s;

    // Descriptive prompt to indicate to the user what is about to happen.
    printf("\nLet's calculate the Area and Perimeter of your triangle!\n");
    
    // Prompt the user for side A input.
    printf("\nWhat is A?:");
    scanf("%d", &a);

    // Prompt the user for side B input.
    printf("\nWhat is B?:");
    scanf("%d", &b);
    
    // Prompt the user for side C input.
    printf("\nWhat is C?:");
    scanf("%d", &c);

    // Calculate Area using Heron's Formula:
    // Get semiperimeter
    s = (a + b + c) / 2;
    // Calculate Area
    A = sqrt(s*(s-a)*(s-b)*(s-c));

    // Calculate Perimeter
    P = a + b + c;

     // Return the results to the user
    printf("\nArea: %f units squared\n", A);
    printf("Perimeter: %f units\n", P);

    return 0;
}