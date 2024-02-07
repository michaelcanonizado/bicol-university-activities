#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

void selectionSort(float array[], int size) {
    unsigned int minIndex;
    float temp;

    printf("\nOuput of SELECTION Sort:");
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
        
        printf("\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%.0f ", array[i]);
        }
    }
}

void insertionSort() {
    printf("\nInsertion sort");
}

void bubbleSort() {
    printf("\nBubble sort");
}

void mergeSort() {
    printf("\nMerge sort");
}

int main(void) {
    char sortingAlgorithms[][50] = {"SELECTION SORT", "INSERTION SORT", "BUBBLE SORT", "MERGE SORT"};

    int sizeOfArray, sortingAlgorithmChoice;
    float array[MAX_ARRAY_SIZE];

    printf("\nEnter the size of the array: ");
    scanf("%d", &sizeOfArray);
    printf("Enter the array elements: ");
    for (int i = 0; i < sizeOfArray; i++) {
        scanf("%f", &array[i]);
    }

    printf("Which sorting algorithm do you want to use?");
    for (int i = 0; i < sizeof(sortingAlgorithms)/sizeof(sortingAlgorithms[0]); i++) {
        printf("\n  %d. %s", i + 1, sortingAlgorithms[i]);
    }
    printf("\nType number of choice: ");
    scanf("%d", &sortingAlgorithmChoice);

    switch(sortingAlgorithmChoice) {
        case 1: 
            selectionSort(array, sizeOfArray);
            break;
        case 2: 
            insertionSort();
            break;
        case 3: 
            bubbleSort();
            break;
        case 4: 
            mergeSort();
            break;
    }

    printf("\n\nSORTED ARRAY: ");
    for(int i = 0; i < sizeOfArray; i++) {
        printf("%.0f ", array[i]);
    }

    return 0;
}