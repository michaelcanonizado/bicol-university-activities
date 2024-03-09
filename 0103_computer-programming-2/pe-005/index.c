#include <stdio.h>

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

    char strings[100];
    char stringBuffer[100];
    int stringsCount = 0;

    fscanf(pInputFile, "%d", &stringsCount);

    while(fscanf(pInputFile, "%s", stringBuffer) != EOF) {
        printf("%s\n", stringBuffer);
    }

    printf("\n\nScanned %d strings!", stringsCount);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}