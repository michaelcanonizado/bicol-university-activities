#include <stdio.h>

int main(void) {
    int num1, num2;

    FILE *inputFile;
    FILE *outputFile;
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "wt");

    if(inputFile == NULL) {
        printf("Input file not found");
        return 1;
    }

    printf("Reading from index.txt...\n");
    fscanf(inputFile, "%d %d", &num1, &num2);

    printf("\nReader values: %d %d\nValue when added: %d", num1, num2, num1+num2);

    printf("\nWriting to output.txt...");
    fprintf(outputFile, "Total: %d\n", num1+num2);
    printf("\nSuccessfully written to output.txt...");

    printf("\n\nTask complete...");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

