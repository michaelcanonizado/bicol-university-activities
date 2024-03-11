#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_OF_STRINGS 999

void toLowerStrings(char *stringsArr[], int stringsCount) {
    // Go through each pointer of the array and dereference its value and turn it to lowercase, using pointer offset notation.
    for (int i = 0; i < stringsCount; i++) {
        int stringOffset = 0;
        char *pString = stringsArr[i];

        while (*(pString + stringOffset) != '\0') {
            *(pString + stringOffset) = tolower(*(pString + stringOffset));
            stringOffset++;
        }
    }
}

void mergeStrings(char *stringsArr[], int leftHalfStart, int leftHalfEnd, int rightHalfStart, int rightHalfEnd) {
    char *tempArray[MAX_STRING_LENGTH];
    int leftIndex = leftHalfStart; 
    int rightIndex = rightHalfStart; 
    int tempIndex = 0;

    while ((leftIndex <= leftHalfEnd) && (rightIndex <= rightHalfEnd)) {
        if(strlen(stringsArr[leftIndex]) < strlen(stringsArr[rightIndex])) {

            tempArray[tempIndex++] = stringsArr[leftIndex++];

        } else if (strlen(stringsArr[leftIndex]) > strlen(stringsArr[rightIndex])) {

            tempArray[tempIndex++] = stringsArr[rightIndex++];

        } else if (strlen(stringsArr[leftIndex]) == strlen(stringsArr[rightIndex])) {
            int stringOffset = 0;

            if (
                strcmp(stringsArr[leftIndex], stringsArr[rightIndex]) < 0
            ) {

                tempArray[tempIndex++] = stringsArr[leftIndex++];

            } else if (
                strcmp(stringsArr[leftIndex], stringsArr[rightIndex]) > 0
            ) {

                tempArray[tempIndex++] = stringsArr[rightIndex++];

            } else if (
                strcmp(stringsArr[leftIndex], stringsArr[rightIndex]) == 0
            ) {

                tempArray[tempIndex++] = stringsArr[rightIndex++];

            }
        }
    }

    while(leftIndex <= leftHalfEnd) {
        tempArray[tempIndex++] = stringsArr[leftIndex++];
    }

    while(rightIndex <= rightHalfEnd) {
        tempArray[tempIndex++] = stringsArr[rightIndex++];
    }

    for (int i = leftHalfStart, j = 0; i <= rightHalfEnd; i++, j++) {
        stringsArr[i] = tempArray[j];
    }
}

void mergeSortStrings(char *stringsArr[], int start, int end, int stringsCount) {
        // Use merge sort to sort the array in lexicographic order, and if the strings have the same length, sort them alphabetically.
    if (start < end) {

        int mid = (start + end) / 2;

        mergeSortStrings(stringsArr, start, mid, stringsCount);
        mergeSortStrings(stringsArr, mid + 1, end, stringsCount);

        mergeStrings(stringsArr, start, mid, mid + 1, end);
    } 
}

int main(int argc, char *argv[]) {
    // Check if user has passed the input and output files
    if (argc <= 1) {
        printf("\nPlease specify the input file and output file names when executing the program...\n\n");
        return 1;
    }

    // Open input and output file pointers
    FILE *pInputFile;
    FILE *pOutputFile;
    pInputFile = fopen(argv[1], "r");
    pOutputFile = fopen(argv[2], "w");

    // if input file is not found, prompt an error
    if (pInputFile == NULL) {
        printf("Error! string.txt is not found!\n");
        return 1;
    }

    // Initialize nessessary arrays and variables
    // Strings will be stored in a array, as malloc is not allowed to be used. The addresses of the strings in the array will then be pointed to by the array of pointers
    char *stringsPointerArray[MAX_NUM_OF_STRINGS] = {NULL};
    char stringsStorage[MAX_NUM_OF_STRINGS][MAX_STRING_LENGTH];
    int stringsCount = 0, tempCount = 0;
    char stringBuffer[100];

    // Scan the first line (strings count) of the input file
    fscanf(pInputFile, "%d", &stringsCount);

    // Scan the strings of the input file until EOF
    while(fscanf(pInputFile, "%s", stringsStorage[tempCount]) != EOF) {
        stringsPointerArray[tempCount] = &stringsStorage[tempCount][0];
        tempCount++;
    }

    // Convert the strings to lowercase
    toLowerStrings(stringsPointerArray, stringsCount);
    // Sort the strings using merge sort. 
    mergeSortStrings(stringsPointerArray, 0, stringsCount-1, stringsCount);

    // Print results to scree and output file
    printf("\n%-15s %-15s      %-5s", "STRING", "MEMORY ADDRESS", "LENGTH");
    printf("\n-------------------------------------------\n");
    for(int i = 0; i < stringsCount; i++) {
        printf("%-15s    %-10p         %-3d\n", stringsPointerArray[i], stringsPointerArray[i], strlen(stringsPointerArray[i]));
    }

    printf("\n");

    // Close file pointers
    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}