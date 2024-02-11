#include <stdio.h>

#define MAX_MATRIX_ROWS 100
#define MAX_MATRIX_COLS 100

void getMatrixTranspose(int result[MAX_MATRIX_COLS][MAX_MATRIX_ROWS], int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void getMatrixRowSum(int result[MAX_MATRIX_ROWS],int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS], int rows, int cols) {
    int rowSum;
    
    for (int i = 0; i < rows; i++) {
        rowSum = 0;

        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }

        result[i] = rowSum;
    }

}

void getMatrixColSum(int result[MAX_MATRIX_COLS],int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS], int rows, int cols) {
    int colSum;
    
    for (int i = 0; i < rows; i++) {
        colSum = 0;

        for (int j = 0; j < cols; j++) {
            colSum += matrix[j][i];
        }

        result[i] = colSum;
    }

}

int getMatrixTotalSum(int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS], int rows, int cols) {
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;

}

int main (void) {
    int matrixRows, matrixCols, matrixTotalSum = 0;
    int matrixRowSum[MAX_MATRIX_ROWS];
    int matrixColSum[MAX_MATRIX_COLS];
    int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];

    int matrixTransposeRows, matrixTransposeCols;
    int matrixTranspose[MAX_MATRIX_COLS][MAX_MATRIX_ROWS];

    // 1.0 | Get matrix values matrix.in
    FILE *pInputFile;
    pInputFile = fopen("matrix.in", "r");

    if (pInputFile == NULL) {
        printf("matrix.in not found...");
        return 1;
    }

    // 1.1 | Get matrix dimentions
    fscanf(pInputFile, "%d %d", &matrixRows, &matrixCols);
    // 1.2 | Get matrix values
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            fscanf(pInputFile, "%d", &matrix[i][j]);
        }
    }

    fclose(pInputFile);

    // 2.0 | Get matrix transpose
    getMatrixTranspose(matrixTranspose, matrix, matrixRows, matrixCols);
    // 2.1 | Get matrix transpose dimentions
    matrixTransposeRows = matrixCols;
    matrixTransposeCols = matrixRows;

    // 3.0 | Get matrix row sum
    getMatrixRowSum(matrixRowSum, matrix, matrixRows, matrixCols);
    // 3.1 | Get matrix col sum
    getMatrixColSum(matrixColSum, matrix, matrixRows, matrixCols);
    // 3.2 | Get matrix total sum
    matrixTotalSum = getMatrixTotalSum(matrix, matrixRows, matrixCols);

    // 4.0 | Exit out if matrix is not a square matrix
    if (matrixRows != matrixCols) {
        return 0;
    }

    printf("\nRows: %d\nCols: %d\n", matrixRows, matrixCols);
    printf("\nMatrix:\n");
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nRows Sum:\n", matrixRows);
    for (int i = 0; i < matrixRows; i++) {
        printf("%5d", matrixRowSum[i]);
    }
    printf("\nCols Sum:\n", matrixCols);
    for (int i = 0; i < matrixCols; i++) {
        printf("%5d", matrixColSum[i]);
    }
    printf("\nTotal Sum: \n%5d\n", matrixTotalSum);

    printf("\n\n");

    return 0;
}