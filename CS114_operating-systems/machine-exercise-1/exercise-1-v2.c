#include <stdio.h>

int main(void) {
    char sourceFileName[256];
    char destinationFileName[256];
    FILE *sourceFile = NULL;
    FILE *destinationFile = NULL;
    int character;

    /* Program Header */
    printf("\n--------------------------------------------------");
    printf("\n--------------File-Copier-Program-V2--------------");
    printf("\n--------------------------------------------------");

    
    /* Prompt for source file */
    printf("\nEnter source file name: ");
    if (scanf("%255s", sourceFileName) != 1) {
        fprintf(stderr, "Error: Could not read source file name.\n");
        return 1;
    }

    /* Open source file */
    sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL) {
        fprintf(stderr, "Error: Source file could not be opened.\n");
        return 2;
    }

    /* Prompt for destination file */
    printf("Enter destination file name: ");
    if (scanf("%255s", destinationFileName) != 1) {
        fprintf(stderr, "Error: Could not read destination file name.\n");
        fclose(sourceFile);
        return 3;
    }

    /* Open destination file */
    destinationFile = fopen(destinationFileName, "wb");
    if (destinationFile == NULL) {
        fprintf(stderr, "Error: Destination file could not be opened.\n");
        fclose(sourceFile);
        return 4;
    }

    /* Copy contents of source file to desintation file */
    while (
        (character = fgetc(sourceFile)) != EOF
    ) {
        if (fputc(character, destinationFile) == EOF) {
            fprintf(stderr, "Error: Something went wrong when copying data.\n");
            fclose(sourceFile);
            fclose(destinationFile);
            return 5;
        }
    }
    
    /* Success Message */
    printf("Successfully copied data\n");

    /* Close file */
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
