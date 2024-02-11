#include <stdio.h>

#define MAX_MATRIX_ROWS 100
#define MAX_MATRIX_COLS 100

int main (void) {
    int rows, cols;
    int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];
    int matrixTranspose[MAX_MATRIX_COLS][MAX_MATRIX_ROWS];

    // 1.0 | GET MATRIX VALUES FROM matrix.in
    FILE *pInputFile;
    pInputFile = fopen("matrix.in", "r");

    if (pInputFile == NULL) {
        printf("matrix.in not found...");
        return 1;
    }

    // 1.1 | Get matrix dimentions
    fscanf(pInputFile, "%d %d", &rows, &cols);
    // 1.2 | Get matrix values
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