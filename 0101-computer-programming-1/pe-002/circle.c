#include <stdio.h>
#include <math.h>

int main(void) {
    // Initialize the variables where inputs are Integers and products are Floats.
    int r;
    float A, C;
    // Initialize the constant PI
    const float PI = 3.14159265;

    // Descriptive prompt to indicate to the user what is about to happen.
    printf("\nLet's calculate the Area and Circumference of your circle!\n");

    // Prompt the user for radius input.
    printf("\nWhat is the radius?:");
    scanf("%d", &r);

    if (r > 0) {
      // Calculate the area
      A = PI * (r * r);
      // Calculate the circumference
      C = 2 * PI * r;

      // Return the results to the user
      printf("\nArea: %f units squared", A);
      printf("\nCircumference: %f units\n\n", C);

      return 0;
    } else {
      // Print error message
      printf("\nInvalid Input. Please make sure all inputs are greater than 0\n");
      printf("Please run the program again\n");

      return 1;
    }
}