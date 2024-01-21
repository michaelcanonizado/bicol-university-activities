#include <stdio.h>

#define MAX_DATA_ARRAY_LENGTH 100

int main(void) {
    int dataArrayLength;
    float dataArray[MAX_DATA_ARRAY_LENGTH];

    FILE *pInputFile;
    pInputFile = fopen("input.txt", "rt");

    if (pInputFile == NULL) {
        printf("input.txt not found...");
        return 1;
    }

    // Read input.txt's first line (array length)
    fscanf(pInputFile, "%d", &dataArrayLength);
    
    // Read input.txt's second line (array data) | Use a while loop and conditionally check if there is still data to be read. Instead of using a for-loop and using dataArrayLength as basis. The array length, ideally, can be determined by 'sizeof(dataArray)/sizeof(dataArray[0])'
    int counter = 0;
    while(fscanf(pInputFile, "%f", &dataArray[counter]) == 1 && counter <= MAX_DATA_ARRAY_LENGTH) {
        counter++;
    }

    printf("Array Length: %d\n", dataArrayLength);
    for (int i = 0; i < dataArrayLength; i++) {
        printf("%f ", dataArray[i]);
    }

    return 0;
}