#include <stdio.h>
#include <math.h>

#define MAX_DATA_ARRAY_LENGTH 100

float getDataMean(float pDataArray[], int dataLength);
float getDataStandardDeviation(float pDataArray[], int dataLength, float dataMean);

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

    // Get data array mean
    float dataMean = getDataMean(dataArray, dataArrayLength);

    printf("\n\nData Mean: %f\n", dataMean);

    float dataStandardDeviation = getDataStandardDeviation(dataArray, dataArrayLength, dataMean);

    printf("Data Standard Deviation: %f\n", dataStandardDeviation);

    return 0;
}

float getDataMean(float pDataArray[], int dataLength) {
    float dataSum = 0;

    // Sum up all the data values
    for(int i = 0; i < dataLength; i++) {
        dataSum += pDataArray[i];
    }

    // Get mean (sum / number of values)
    float dataMean = dataSum / dataLength;

    return dataMean;
}

float getDataStandardDeviation(float pDataArray[], int dataLength, float dataMean) {
    float sumofValueMinusMeanSquared = 0;
    float variance, standardDeviation;

    // Sum up the squares of value - mean
    for(int i = 0; i < dataLength; i++) {
        sumofValueMinusMeanSquared += pow(pDataArray[i] - dataMean, 2);
    }

    // Get variance
    variance = sumofValueMinusMeanSquared/(dataLength - 1);

    // Sqaure root variance to get standard deviation
    standardDeviation =  sqrt(variance);

    return standardDeviation;
}
