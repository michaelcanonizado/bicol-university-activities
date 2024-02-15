#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 50
#define MAX_NUM_WORDS 100

int main(void) {
    char singularStrings[MAX_NUM_WORDS][MAX_STR_LEN], strBuffer[MAX_STR_LEN];
    int singularStringsCount = 0;
    
    FILE *pInputFile;
    pInputFile = fopen("singular.in", "r");

    if (pInputFile == NULL) {
        printf("Error! singular.in file not found!");
        return 1;
    }

    while(fscanf(pInputFile, "%s", strBuffer) != EOF) {
        for(int i = 0; strBuffer[i] != '\0'; i++) {
            strBuffer[i] = tolower(strBuffer[i]);
        }

        strcpy(singularStrings[singularStringsCount],strBuffer);

        singularStringsCount++;
    }

    fclose(pInputFile);

    for (int i = 0; i < singularStringsCount; i++) {
        printf("\n%s", singularStrings[i]);
    }

    return 0;
}