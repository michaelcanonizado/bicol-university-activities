#include <stdio.h>

int main(void) {
    char singularString[100][100];
    int singularStringsCount = 0;
    FILE *pInputFile;
    pInputFile = fopen("singular.in", "r");

    if (pInputFile == NULL) {
        printf("Error! singular.in file not found!");
        return 1;
    }

    while(fscanf(pInputFile, "%s", singularString[singularStringsCount]) != EOF) {
        singularStringsCount++;
    }

    fclose(pInputFile);

    for (int i = 0; i < singularStringsCount; i++) {
        printf("\n%s", singularString[i]);
    }

    return 0;
}