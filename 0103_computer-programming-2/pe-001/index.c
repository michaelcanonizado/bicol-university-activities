// Canonizado, Michael Xavier E. | BSCS 1-A
// This program will take in floating point data from an input.dat file where the first line is the size of the array, and the second line is the list of values of the array. It will read the file and compute the mean and standard deviation. Where it will then output the results in an output.dat file and print the results to the terminal.

#include <stdio.h>
#include <math.h>

#define MAX_DATA_ARRAY_LENGTH 100

float getDataMean(float pDataArray[], int dataLength);
float getDataStandardDeviation(float pDataArray[], int dataLength, float dataMean);

int main(void) {
    int dataArrayLength;
    float dataArray[MAX_DATA_ARRAY_LENGTH];

    FILE *pInputFile;
    pInputFile = fopen("input.dat", "r");
    FILE *pOutputFile;
    pOutputFile = fopen("output.dat", "w");

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
    // Get data array standard deviation
    float dataStandardDeviation = getDataStandardDeviation(dataArray, dataArrayLength, dataMean);

    // Print results to screen
    printf("The mean is: %.4f.\n", dataMean);
    printf("The standard deviation is: %.4f.\n", dataStandardDeviation);
    printf("\nTable of differences between the data values and mean deviation");
    printf("\n %-5s %8s %19s", "Index", "Data", "Data-Mean");
    for(int i = 0; i < dataArrayLength; i++) {
        printf("\n %-5i %8.2f %16.2f", i, dataArray[i], dataArray[i]-dataMean);
    }
    printf("\n\n");

    // Output results to output.dat
    fprintf(pOutputFile, "The mean is: %.4f.\n", dataMean);
    fprintf(pOutputFile, "The standard deviation is: %.4f.\n", dataStandardDeviation);
    fprintf(pOutputFile, "\nTable of differences between the data values and mean deviation");
    fprintf(pOutputFile, "\n %-5s %8s %19s", "Index", "Data", "Data-Mean");
    for(int i = 0; i < dataArrayLength; i++) {
        fprintf(pOutputFile, "\n %-5i %8.2f %16.2f", i, dataArray[i], dataArray[i]-dataMean);
    }
    fprintf(pOutputFile, "\n");

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
