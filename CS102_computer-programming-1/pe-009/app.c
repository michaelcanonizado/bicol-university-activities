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

    printf("\n%-10s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s\n", "INTEGER","0s","1s","2s","3s","4s","5s","6s","7s","8s","9s");
    printf("------------------------------------------------------------");

    while (1) {
        fscanf(inputFile, "%d", &integer);
        if (integer == 0) {
            printf("\n\n");
            break;
        }

        printf("\n%-10d", integer);

        for (int digit = 0; digit <= 9; digit++) {
                int result = frequencyOfDigit(integer, digit);
                printf("%4d ", result);

                digitCounter = 0;
        }

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