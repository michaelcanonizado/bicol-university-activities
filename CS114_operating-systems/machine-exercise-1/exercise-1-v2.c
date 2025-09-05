#include <stdio.h>

int main(void) {
    char sourceFileName[256];
    char destinationFileName[256];
    FILE *sourceFile = NULL;
    FILE *destinationFile = NULL;
    int character;

    printf("\n--------------------------------------------------");
    printf("\n--------------File-Copier-Program-V2--------------");
    printf("\n--------------------------------------------------");

    printf("\nEnter source file name: ");
    if (scanf("%255s", sourceFileName) != 1) {
        fprintf(stderr, "Error reading source file name.\n");
        return 1;
    }

    sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL) {
        fprintf(stderr, "Error: Source file '%s' does not exist or cannot be opened.\n", sourceFileName);
        return 2;
    }

    printf("Enter destination file name: ");
    if (scanf("%255s", destinationFileName) != 1) {
        fprintf(stderr, "Error reading destination file name.\n");
        fclose(sourceFile);
        return 3;
    }

    destinationFile = fopen(destinationFileName, "wb");
    if (destinationFile == NULL) {
        fprintf(stderr, "Error: Destination file '%s' cannot be created.\n", destinationFileName);
        fclose(sourceFile);
        return 4;
    }

    while (
        (character = fgetc(sourceFile)) != EOF
    ) {
        if (fputc(character, destinationFile) == EOF) {
            fprintf(stderr, "Error writing to destination file '%s'.\n", destinationFileName);
            fclose(sourceFile);
            fclose(destinationFile);
            return 5;
        }
    }

    printf("Successfully copied from '%s' to '%s'.\n", sourceFileName, destinationFileName);

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
