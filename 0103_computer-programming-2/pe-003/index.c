#include <stdio.h>

#define MAX_MATRIX_ROWS 100
#define MAX_MATRIX_COLS 100

int main (void) {
    int rows, cols;
    int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];

    FILE *pInputFile;
    pInputFile = fopen("matrix.in", "r");

    if (pInputFile == NULL) {
        printf("matrix.in not found...");
        return 1;
    }

    fscanf(pInputFile, "%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(pInputFile, "%d", &matrix[i][j]);
        }
    }

    fclose(pInputFile);

    printf("\nRows: %d\nCols: %d\n\n", rows, cols);
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}