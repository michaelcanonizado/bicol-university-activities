#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 50
#define MAX_NUM_WORDS 100

void toPlural(char pluralStrings[MAX_NUM_WORDS][MAX_STR_LEN], char singularStrings[MAX_NUM_WORDS][MAX_STR_LEN], int array_length) {
    
    for (int i = 0; i <= array_length; i++) {

        int stringLength = strlen(singularStrings[i]);
        strcpy(pluralStrings[i], singularStrings[i]);

        if (
            singularStrings[i][stringLength - 1] == 's' ||
            singularStrings[i][stringLength - 1] == 'x' ||
            singularStrings[i][stringLength - 1] == 'z' ||
            (singularStrings[i][stringLength - 2] == 's' && singularStrings[i][stringLength -1] == 'h') ||
            (singularStrings[i][stringLength - 2] == 'c' && singularStrings[i][stringLength -1] == 'h')
            ) {

            strcat(pluralStrings[i], "es");

        } else if (singularStrings[i][stringLength - 1] == 'y') {

            if (
                singularStrings[i][stringLength - 2] == 'a' || 
                singularStrings[i][stringLength - 2] == 'e' || 
                singularStrings[i][stringLength - 2] == 'i' || 
                singularStrings[i][stringLength - 2] == 'o' || 
                singularStrings[i][stringLength - 2] == 'u') {

                strcat(pluralStrings[i], "s");

            } else {

                pluralStrings[i][stringLength - 1] = 'i';
                strcat(pluralStrings[i], "es");

            }

        } else {

            strcat(pluralStrings[i], "s");

        }


    }

}

int main(void) {
    char singularStrings[MAX_NUM_WORDS][MAX_STR_LEN], pluralStrings[MAX_NUM_WORDS][MAX_STR_LEN], strBuffer[MAX_STR_LEN];
    int singularStringsCount = 0;

    FILE *pInputFile;
    pInputFile = fopen("singular.in", "r");
    FILE *pOutputFile;
    pOutputFile = fopen("plural.out", "w");

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

    toPlural(pluralStrings, singularStrings, singularStringsCount);

    fprintf(pOutputFile, "%-13s %-13s", "SINGULAR", "PLURAL");
    fprintf(pOutputFile, "\n---------------------------");
    for (int i = 0; i < singularStringsCount; i++) {
        fprintf(pOutputFile, "\n%-13s %-13s", singularStrings[i], pluralStrings[i]);
    }
    printf("\n\n");

    fclose(pOutputFile);

    return 0;
}