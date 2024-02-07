#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

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

    printf("\n\nCHOSEN ALGO: %s\n\n", sortingAlgorithms[sortingAlgorithmChoice - 1]);

    return 0;
}