// Michael Xavier E. Canonizado | BSCS 1A
// A program that converts scanned singular words from a file called 'singular.in' and converts it to plural, and outputs it into a file called 'plural.out' 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 50
#define MAX_NUM_WORDS 100

void toPlural(char pluralStrings[MAX_NUM_WORDS][MAX_STR_LEN], char singularStrings[MAX_NUM_WORDS][MAX_STR_LEN], int array_length) {
    // 2.1 | Go through each word converting to plural
    for (int i = 0; i <= array_length; i++) {

        // 2.2 | Copy current word to pluralStrings[]
        int stringLength = strlen(singularStrings[i]);
        strcpy(pluralStrings[i], singularStrings[i]);

        // 2.3 | Convert current word in pluralStrings[] to plural by check the last characters
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
    // Store scanned and converted words in an array, and use a buffer to temporarily store the currently scanned word and covert it to lowercase before pushing in array.
    char singularStrings[MAX_NUM_WORDS][MAX_STR_LEN], pluralStrings[MAX_NUM_WORDS][MAX_STR_LEN], strBuffer[MAX_STR_LEN];
    // Count to keep track of number of words scanned
    int singularStringsCount = 0;

    // Input and output files
    FILE *pInputFile;
    pInputFile = fopen("singular.in", "r");
    FILE *pOutputFile;
    pOutputFile = fopen("plural.out", "w");

    if (pInputFile == NULL) {
        printf("Error! singular.in file not found!");
        return 1;
    }

    // 1.0 | Continuosly scan words will EOF. Temporarily store word in buffer
    while(fscanf(pInputFile, "%s", strBuffer) != EOF) {
        // 1.1 | Convert word in buffer to lowercase
        for(int i = 0; strBuffer[i] != '\0'; i++) {
            strBuffer[i] = tolower(strBuffer[i]);
        }

        // 1.2 | Push lowercased word in buffer to singularStrings array
        strcpy(singularStrings[singularStringsCount],strBuffer);

        // 1.3 | Increment strings count
        singularStringsCount++;
    }

    // Close input file after scanning
    fclose(pInputFile);

    // 2.0 | Convert each word in singularStrings[] to plural, and push into pluralStrings[]
    toPlural(pluralStrings, singularStrings, singularStringsCount);

    // 3.0 | Output before and after results in plural.out
    fprintf(pOutputFile, "%-13s %-13s", "SINGULAR", "PLURAL");
    fprintf(pOutputFile, "\n---------------------------");
    for (int i = 0; i < singularStringsCount; i++) {
        fprintf(pOutputFile, "\n%-13s %-13s", singularStrings[i], pluralStrings[i]);
    }
    printf("\n\n");

    fclose(pOutputFile);

    return 0;
}