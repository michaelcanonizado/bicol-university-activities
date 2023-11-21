#include <stdio.h>
#include <math.h>

int digitCounter = 0;

int frequencyOfDigit(int integer, int digit);

int main (void) {
    int integer = 0;

    FILE*inputFile;
    inputFile = fopen("integers.txt", "rt");
    if (inputFile == NULL) {
        perror("Error opening the integers.txt");
        return 1;
    }

    while (1) {
        fscanf(inputFile, "%d", &integer);
        if (integer == 0) {
            printf("REACHED 0");
            break;
        }

        for (int digit = 0; digit <= 9; digit++) {
                int result = frequencyOfDigit(integer, digit);
                // printf("\n%ds in %d is: %d", digit, integer, result);
                digitCounter = 0;
        }

        printf("\n");    
    }
    
    fclose(inputFile);
    return 0;
}

int frequencyOfDigit(int integer, int digit) {
    // If inputted integer is negative(-), multiply it by -1, as signs won't affect frequency of the digit.
    if (integer < 0) {
        integer = integer * -1;
    }

    if (integer >= 0 && integer <= 9) {
        if (integer == digit) {
            digitCounter++;
        }
        // printf("last modulo: %d\n", integer % 10);
        return 1;
    }

    // printf("modulo: %d\n", integer % 10); 
    if ((integer % 10) == digit) {
        digitCounter++;
    }
        
    frequencyOfDigit(integer/10, digit);

    return digitCounter;
}