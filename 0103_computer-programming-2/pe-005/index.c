#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_OF_STRINGS 100

void toLowerStrings(char *stringsArr[], int stringsCount) {

}

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

    char *stringsPointerArray[MAX_NUM_OF_STRINGS];
    char stringsStorage[MAX_NUM_OF_STRINGS][MAX_STRING_LENGTH];
    int stringsCount = 0, tempCount = 0;
    char stringBuffer[100];

    fscanf(pInputFile, "%d", &stringsCount);

    while(fscanf(pInputFile, "%s", stringsStorage[tempCount]) != EOF) {
        stringsPointerArray[tempCount] = &stringsStorage[tempCount][0];
        tempCount++;
    }

    for(int i = 0; i < stringsCount; i++) {
        printf("string: %-15s - address: %10p\n", stringsStorage[i], &stringsStorage[i]);
    }
    printf("\n");
    for(int i = 0; i < stringsCount; i++) {
        printf("string: %-15s - address: %10p\n", stringsPointerArray[i], stringsPointerArray[i]);
    }

    printf("\n\nScanned %d strings!", stringsCount);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}