// Michael Xavier E. Canonizado
// A program that sorts an array. It prompts for the size of the array, the values of the array, and the type of sorting algorithm to be used to sort the array. I will then use that sorting algortihm to sort the array and print the state of the array after each iteration/recursion and output the final sorted array. 

#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

void selectionSort(int array[], int size, FILE *pOutputFile) {
    // Use a flag to indicate whether any unsorted values are found.
    int minIndex, isNotSortedFlag = 0;
    int temp;

    for (int i = 0; i < size - 1; i++) {
        minIndex = i;

        // Look for the smallest value
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
                isNotSortedFlag++;
            }

            // Add to flag to indicate that the array is not yet sorted
            if (array[j - 1] > array[j]) {
                isNotSortedFlag++;
            }
        }

        // Swap the smallest value at the current index
        if (minIndex != i) {
            temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
        
        // If we've looped through all items in the array and everything is in order, break out.
        if (isNotSortedFlag == 0) {
            break;
        }
        isNotSortedFlag = 0;
        
        // Print array state after each iteration
        printf("\n Iteration i=%d: ", i);
        fprintf(pOutputFile, "\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
            fprintf(pOutputFile, "%d ", array[i]);
        }
    }
}

void insertionSort(int array[], int size, FILE *pOutputFile) {
    int temp;

    for (int i = 1; i < size; i++) {
        // Check if there is a smaller value to the left of the item
        for (int j = i - 1; j >= 0; j--) {
            // If value to the left is greater, break out of the loop
            if (array[j] < array[j + 1]) {
                break;
            }

            // If value to the left is smaller, swap item
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }

        // Print array state after each iteration
        printf("\n Iteration i=%d: ", i);
        fprintf(pOutputFile, "\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
            fprintf(pOutputFile, "%d ", array[i]);
        }
    }
}

void bubbleSort(int array[], int size, FILE *pOutputFile) {
    // Use flag to check if unsorted values are left
    int temp, isNotSortedFlag = 0;

    for (int i = 0; i < (size - 1); i++) {
        // Bubble up value if it is greater than the value to its right
        for (int j = 0; j < (size - 1); j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isNotSortedFlag++;
            }
        }

        // If loop has iterated through the whole array without making any swaps, break out of the loop as array is sorted
        if (isNotSortedFlag == 0) {
            break;
        }
        isNotSortedFlag = 0;

        // Print array state after each iteration  
        printf("\n Iteration i=%d: ", i);
        fprintf(pOutputFile, "\n Iteration i=%d: ", i);
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
            fprintf(pOutputFile, "%d ", array[i]);
        }
    }
}

void merge(int array[], int leftHalfStart, int leftHalfEnd, int rightHalfStart, int rightHalfEnd) {
    int tempArray[MAX_ARRAY_SIZE];
    int leftIndex = leftHalfStart; 
    int rightIndex = rightHalfStart; 
    int tempIndex = 0;

    // Compare items of the sorted halves and sort in a temporary array
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

    // Transfer temporary array to the original array
    for (int i = leftHalfStart, j = 0; i <= rightHalfEnd; i++, j++) {
        array[i] = tempArray[j];
    }
}
void mergeSort(int array[], int start, int end, int size, FILE *pOutputFile) {
    // Recurse only if there is more than 1 item
    if (start < end) {
        // Cut array in half
        int mid = (start + end) / 2;
        // Sort the 2 halves
        mergeSort(array, start, mid, size, pOutputFile);
        mergeSort(array, mid + 1, end, size, pOutputFile);

        // Merge the sorted halves
        merge(array, start, mid, mid + 1, end);

        // Print array state after each iteration
        printf("\n Recursion: ");
        fprintf(pOutputFile, "\n Recursion: ");
        for(int i = 0; i < size; i++) {
            printf("%d ", array[i]);
            fprintf(pOutputFile, "%d ", array[i]);
        }
    } 
}

int main(void) {
    // Store array names in an array, use a for loop to display the choices and use the indexes as numbering
    char sortingAlgorithms[][50] = {"SELECTION SORT", "INSERTION SORT", "BUBBLE SORT", "MERGE SORT"};

    int sizeOfArray, sortingAlgorithmChoice;
    int array[MAX_ARRAY_SIZE];

    FILE *pOutputFile;
    pOutputFile = fopen("output.dat", "w");

    // Ask user for the size of the array and elements of the array
    printf("\nEnter the size of the array: ");
    scanf("%d", &sizeOfArray);
    printf("Enter the array elements: ");
    for (int i = 0; i < sizeOfArray; i++) {
        scanf("%d", &array[i]);
    }

    // Output to output.dat
    fprintf(pOutputFile, "Enter the size of the array: %d", sizeOfArray);
    fprintf(pOutputFile, "\nEnter the array elements: ");
    for (int i = 0; i < sizeOfArray; i++) {
        fprintf(pOutputFile, "%d ", array[i]);
    }

    // Ask user for what algorithm to use
    fprintf(pOutputFile, "\nWhich sorting algorithm do you want to use?");
    printf("Which sorting algorithm do you want to use?");
    for (int i = 0; i < sizeof(sortingAlgorithms)/sizeof(sortingAlgorithms[0]); i++) {
        printf("\n  %d. %s", i + 1, sortingAlgorithms[i]);
        fprintf(pOutputFile, "\n  %d. %s", i + 1, sortingAlgorithms[i]);
    }
    printf("\n  Type number of choice: ");
    scanf("%d", &sortingAlgorithmChoice);

    fprintf(pOutputFile, "\n  Type number of choice: %d\n", sortingAlgorithmChoice);


    // Switch through user's choice
    switch(sortingAlgorithmChoice) {
        case 1:
            printf("\nOuput of SELECTION Sort:");
            fprintf(pOutputFile, "\nOuput of SELECTION Sort:");
            selectionSort(array, sizeOfArray, pOutputFile);
            break;
        case 2:
            printf("\nOuput of INSERTION Sort:");
            fprintf(pOutputFile, "\nOuput of INSERTION Sort:");
            insertionSort(array, sizeOfArray, pOutputFile);
            break;
        case 3:
            printf("\nOuput of BUBBLE Sort:");
            fprintf(pOutputFile, "\nOuput of BUBBLE Sort:");
            bubbleSort(array, sizeOfArray, pOutputFile);
            break;
        case 4: 
            printf("\nOuput of MERGE Sort:");
            fprintf(pOutputFile, "\nOuput of MERGE Sort:");
            mergeSort(array, 0, sizeOfArray - 1, sizeOfArray, pOutputFile);
            break;
    }

    // Print Sorted Array
    printf("\n\nSorted Array: ");
    fprintf(pOutputFile, "\n\nSorted Array: ");
    for(int i = 0; i < sizeOfArray; i++) {
        printf("%d ", array[i]);
        fprintf(pOutputFile, "%d ", array[i]);
    }
    printf("\n\n");

    return 0;
}