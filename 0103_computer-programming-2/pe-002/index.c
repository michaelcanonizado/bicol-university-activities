#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

void selectionSort(int array[], int size) {
    int minIndex, isNotSortedFlag = 0;
    int temp;

    printf("\nOuput of SELECTION Sort:");
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
                isNotSortedFlag++;
            }

            if (array[j - 1] > array[j]) {
                isNotSortedFlag++;
            }
        }

        if (minIndex != i) {
            temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
        
        if ((isNotSortedFlag == 0) && (i)) {
            break;
        }
        isNotSortedFlag = 0;
        
        printf("\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    }
}

void insertionSort(int array[], int size) {
    int temp;

    printf("\nOuput of INSERTION Sort:");
    for (int i = 1; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (array[j] < array[j + 1]) {
                break;
            }

            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }

        printf("\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    }
}

void bubbleSort(int array[], int size) {
    int temp;

    printf("\nOuput of BUBBLE Sort:");
    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < (size - 1); j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        
        printf("\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    }
}

void mergeSort() {
    printf("\nMerge sort");
}

int main(void) {
    char sortingAlgorithms[][50] = {"SELECTION SORT", "INSERTION SORT", "BUBBLE SORT", "MERGE SORT"};

    int sizeOfArray, sortingAlgorithmChoice;
    int array[MAX_ARRAY_SIZE];

    printf("\nEnter the size of the array: ");
    scanf("%d", &sizeOfArray);
    printf("Enter the array elements: ");
    for (int i = 0; i < sizeOfArray; i++) {
        scanf("%d", &array[i]);
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
            insertionSort(array, sizeOfArray);
            break;
        case 3: 
            bubbleSort(array, sizeOfArray);
            break;
        case 4: 
            mergeSort();
            break;
    }

    printf("\n\nSORTED ARRAY: ");
    for(int i = 0; i < sizeOfArray; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}