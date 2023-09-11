#include <stdio.h>
#include <math.h>

int main() {
    // Initialize the variables where inputs are Integers and products are Floats.
    int r;
    float A, P;
    // Initialize the constant PI
    const float PI = 3.14159265;

    // Descriptive prompt to indicate to the user what is about to happen.
    printf("\nLet's calculate the Area and Perimeter of your circle!\n");

    // Prompt the user for radius input.
    printf("\nWhat is the radius?:");
    scanf("%d", &r);

    // Calculate the area
    A = PI * (r * r);
    // Calculate the perimeter
    P = 2 * PI * r;

  // Return the results to the user
    printf("\nArea: %f units squared", A);
    printf("\nPerimeter: %f units\n\n", P);

    return 0;
}