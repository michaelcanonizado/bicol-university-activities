#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_OF_STRINGS 100

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("\nPlease specify the input file and output file names when executing the program...\n\n");
        return 1;
    }

    printf("\narg 0: %s\n", argv[0]);
    printf("arg 1: %s\n", argv[1]);
    printf("arg 2: %s\n\n", argv[2]);

    FILE *pInputFile;
    FILE *pOutputFile;
    pInputFile = fopen(argv[1], "r");
    pOutputFile = fopen(argv[2], "w");

    if (pInputFile == NULL) {
        printf("Error! string.txt is not found!\n");
        return 1;
    }

    char unsortedStrings[MAX_NUM_OF_STRINGS][MAX_STRING_LENGTH];
    char sortedStrings[MAX_NUM_OF_STRINGS][MAX_STRING_LENGTH];
    int stringsCount = 0, tempCount = 0;
    char stringBuffer[100];

    fscanf(pInputFile, "%d", &stringsCount);

    while(fscanf(pInputFile, "%s", stringBuffer) != EOF) {
        for(int i = 0; i < strlen(stringBuffer); i++) {
            unsortedStrings[tempCount][i] = tolower(stringBuffer[i]);
        }
        tempCount++;
    }

    for(int i = 0; i < stringsCount; i++) {
        printf("string: %s\n", unsortedStrings[i]);
    }

    printf("\n\nScanned %d strings!", stringsCount);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}