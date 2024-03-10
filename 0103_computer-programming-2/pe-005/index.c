#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_OF_STRINGS 100

void toLowerStrings(char *stringsArr[], int stringsCount) {
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

    // Compare items of the sorted halves and sort in a temporary array
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
    if (start < end) {

        int mid = (start + end) / 2;

        mergeSortStrings(stringsArr, start, mid, stringsCount);
        mergeSortStrings(stringsArr, mid + 1, end, stringsCount);

        mergeStrings(stringsArr, start, mid, mid + 1, end);
    } 
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

    char *stringsPointerArray[MAX_NUM_OF_STRINGS] = {NULL};
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
    toLowerStrings(stringsPointerArray, stringsCount);
    mergeSortStrings(stringsPointerArray, 0, stringsCount-1, stringsCount);
    printf("\n");

    for(int i = 0; i < stringsCount; i++) {
        printf("string: %-15s - address: %10p\n", stringsPointerArray[i], stringsPointerArray[i]);
    }

    printf("\n\nScanned %d strings!", stringsCount);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}