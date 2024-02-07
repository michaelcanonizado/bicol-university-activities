#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

void selectionSort() {
    printf("\nSelection sort");
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
            selectionSort();
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

    return 0;
}