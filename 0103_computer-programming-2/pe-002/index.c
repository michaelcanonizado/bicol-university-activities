#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

void selectionSort(int array[], int size) {
    //
    int minIndex, isNotSortedFlag = 0;
    int temp;

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
        
        if (isNotSortedFlag == 0) {
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
    int temp, isNotSortedFlag = 0;

    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < (size - 1); j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isNotSortedFlag++;
            }
        }

        if (isNotSortedFlag == 0) {
            break;
        }
        isNotSortedFlag = 0;
        
        printf("\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    }
}

void merge(int array[], int leftHalfStart, int leftHalfEnd, int rightHalfStart, int rightHalfEnd) {
    int tempArray[MAX_ARRAY_SIZE];
    int leftIndex = leftHalfStart; 
    int rightIndex = rightHalfStart; 
    int tempIndex = 0;

    while ((leftIndex <= leftHalfEnd) && (rightIndex <= rightHalfEnd)) {
        if(array[leftIndex] < array[rightIndex]) {
            tempArray[tempIndex++] = array[leftIndex++];
        } else {
            tempArray[tempIndex++] = array[rightIndex++];
        }
    }

    while(leftIndex <= leftHalfEnd) {
        tempArray[tempIndex++] = array[leftIndex++];
    }

    while(rightIndex <= rightHalfEnd) {
        tempArray[tempIndex++] = array[rightIndex++];
    }

    for (int i = leftHalfStart, j = 0; i <= rightHalfEnd; i++, j++) {
        array[i] = tempArray[j];
    }
}
void mergeSort(int array[], int start, int end, int size) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(array, start, mid, size);
        mergeSort(array, mid + 1, end, size);

        merge(array, start, mid, mid + 1, end);

        printf("\n Recursion: ");
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    } 
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
    printf("\n  Type number of choice: ");
    scanf("%d", &sortingAlgorithmChoice);

    switch(sortingAlgorithmChoice) {
        case 1:
            printf("\nOuput of SELECTION Sort:");
            selectionSort(array, sizeOfArray);
            break;
        case 2:
            printf("\nOuput of INSERTION Sort:");
            insertionSort(array, sizeOfArray);
            break;
        case 3:
            printf("\nOuput of BUBBLE Sort:");
            bubbleSort(array, sizeOfArray);
            break;
        case 4: 
            printf("\nOuput of MERGE Sort:");
            mergeSort(array, 0, sizeOfArray - 1, sizeOfArray);
            break;
    }

    printf("\n\nSorted Array: ");
    for(int i = 0; i < sizeOfArray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    return 0;
}