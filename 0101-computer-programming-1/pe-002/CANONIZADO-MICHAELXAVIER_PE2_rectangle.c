#include <stdio.h>

int main(void) {
    // Initialize the variables where inputs are Integers and products are Floats
    int L, W;
    float A, P;

    // Descriptive prompt to indicate to the user what is about to happen
    printf("\nLet's calculate the Area and Perimeter of your rectangle!\n");
    
    // Prompt the user for lenght input
    printf("\nWhat is the length?:");
    scanf("%d", &L);

    // Prompt the user for width input
    printf("\nWhat is the Width?:");
    scanf("%d", &W);

    // Checks whether inputs are valid (greater than 0)
    if ((W > 0) && (L > 0)) {
        // Calculate the area
        A = L * W;

        // Calculate the perimeter
        P = (2*L) + (2*W);

        // Return the results to the user
        printf("\nArea: %f units squared\n", A);
        printf("Perimeter: %f units\n", P);

        return 0;
    } else {
        // Print error message
        printf("\nInvalid Inputs. Please make sure all inputs are greater than 0\n");
        printf("Please run the program again\n");

        return 1;
    }
}