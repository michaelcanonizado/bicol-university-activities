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

    for (int i = 0; i < cols; i++) {
        colSum = 0;
        for (int j = 0; j < rows; j++) {
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

int getMatrixUpperTriangularSum(int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS], int dimension) {
    int sum = 0;

    for (int i = 0; i < (dimension - 1); i++) {
        for (int j = i + 1; j < dimension; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int getMatrixLowerTriangularSum(int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS], int dimension) {
    int sum = 0;

    for (int i = 1; i < dimension; i++) {
        for (int j = 0; j < i; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int main (void) {
    int matrixRows, matrixCols, matrixTotalSum = 0, matrixUpperTriangularSum = 0, matrixLowerTriangularSum = 0;
    int matrixRowSum[MAX_MATRIX_ROWS];
    int matrixColSum[MAX_MATRIX_COLS];
    int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];

    int matrixTransposeRows, matrixTransposeCols, matrixTransposeTotalSum = 0, matrixTransposeUpperTriangularSum = 0, matrixTransposeLowerTriangularSum = 0;
    int matrixTransposeRowSum[MAX_MATRIX_ROWS];
    int matrixTransposeColSum[MAX_MATRIX_COLS];
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

    // 3.3 | Get matrix transpose row sum
    getMatrixRowSum(matrixTransposeRowSum, matrixTranspose, matrixTransposeRows, matrixTransposeCols);
    // 3.4 | Get matrix transpose col sum
    getMatrixColSum(matrixTransposeColSum, matrixTranspose, matrixTransposeRows, matrixTransposeCols);
    // 3.5 | Get matrix transpose total sum
    matrixTransposeTotalSum = getMatrixTotalSum(matrixTranspose, matrixTransposeRows, matrixTransposeCols);

    // 4.0 | Exit out if matrix is not a square matrix
    if (1) {
        // 5.0 | Print Original Matrix
        printf("Rows: %d, Cols: %d\n", matrixRows, matrixCols);
        printf("\nOriginal Matrix: Rectangular Matrix\n");
        // 5.1 | Matrix Header
        printf("             ");
        for (int i = 0; i < matrixCols; i++) {
            printf("%3c ", ' ');
        }
        printf("%-4s", "  Sum-of_Row");
        // 5.2 | Matrix values and sum-of-rows
        for (int i = 0; i < matrixRows; i++) {
            printf("\n             ");
            for (int j = 0; j < matrixCols; j++) {
                printf("%3d ", matrix[i][j]);
            }
            printf(" | %3d ", matrixRowSum[i]);
        }
        // 5.3 | Matrix sum-of-columns
        printf("\n              -------------------------");
        printf("\nSum-of-Colum:");
        for (int i = 0; i < matrixCols; i++) {
            printf("%3d ", matrixColSum[i]);
        }
        // 5.4 | Matrix total sum
        printf(" | %3d", matrixTotalSum);

        printf("\n\n");

        
        printf("Rows: %d, Cols: %d\n", matrixTransposeRows, matrixTransposeCols);
        printf("\nTranspose of the matrix\n");
        
        printf("             ");
        for (int i = 0; i < matrixTransposeCols; i++) {
            printf("%3c ", ' ');
        }
        printf("%-4s", "  Sum-of_Row");
        
        for (int i = 0; i < matrixTransposeRows; i++) {
            printf("\n             ");
            for (int j = 0; j < matrixTransposeCols; j++) {
                printf("%3d ", matrixTranspose[i][j]);
            }
            printf(" | %3d ", matrixTransposeRowSum[i]);
        }
        
        printf("\n              -------------------------");
        printf("\nSum-of-Colum:");
        for (int i = 0; i < matrixTransposeCols; i++) {
            printf("%3d ", matrixTransposeColSum[i]);
        }
        
        printf(" | %3d", matrixTransposeTotalSum);

        printf("\n\n");

        return 0;
    }

    matrixUpperTriangularSum = getMatrixUpperTriangularSum(matrix, matrixRows);
    matrixLowerTriangularSum = getMatrixLowerTriangularSum(matrix, matrixRows);

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
    printf("\nTotal Sum: \n%5d", matrixTotalSum);
    printf("\nUpper T Sum: \n%5d", matrixUpperTriangularSum);
    printf("\nLower T Sum: \n%5d", matrixLowerTriangularSum);

    printf("\n\n");

    return 0;
}