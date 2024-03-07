#include <stdio.h>

int main(void) {

    FILE *pInputFile;
    pInputFile = fopen("strings.txt", "r");

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

    return 0;
}