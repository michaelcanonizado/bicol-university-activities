#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

int main(void) {
    int sizeOfArray;
    float array[MAX_ARRAY_SIZE];

    printf("\nEnter the size of the array: ");
    scanf("%d", &sizeOfArray);
    printf("Enter the array elements: ");
    for (int i = 0; i < sizeOfArray; i++) {
        scanf("%f", &array[i]);
    }

    printf("\nEntered values: ");
    for (int i = 0; i < sizeOfArray; i++) {
        printf("%f, ", array[i]);
    }

    return 0;
}