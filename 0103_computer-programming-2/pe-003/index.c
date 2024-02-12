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

int getMatrixDiagonalSum(int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS], int dimension) {
    int sum = 0;

    for (int i = 0; i < dimension; i++) {
        sum += matrix[i][i];
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
    int matrixRows, matrixCols, matrixTotalSum = 0, matrixMainDiagonalSum = 0, matrixUpperTriangularSum = 0, matrixLowerTriangularSum = 0;
    int matrixRowSum[MAX_MATRIX_ROWS];
    int matrixColSum[MAX_MATRIX_COLS];
    int matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];

    int matrixTransposeRows, matrixTransposeCols, matrixTransposeMainDiagonalSum = 0, matrixTransposeTotalSum = 0, matrixTransposeUpperTriangularSum = 0, matrixTransposeLowerTriangularSum = 0;
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
    if (matrixRows != matrixCols) {
        // 5.0 | Print Original Matrix
        printf("\nOriginal Matrix: Rectangular Matrix\n");
        // 5.1 | Matrix Header
        printf("              ");
        for (int i = 0; i < matrixCols; i++) {
            printf("%3c ", ' ');
        }
        printf("%-4s", "  Sum-of-Row");
        // 5.2 | Matrix values and sum-of-rows
        for (int i = 0; i < matrixRows; i++) {
            printf("\n              ");
            for (int j = 0; j < matrixCols; j++) {
                printf("%3d ", matrix[i][j]);
            }
            printf(" | %3d ", matrixRowSum[i]);
        }
        // 5.3 | Matrix sum-of-columns
        printf("\n              -------------------------");
        printf("\nSum-of-Column:");
        for (int i = 0; i < matrixCols; i++) {
            printf("%3d ", matrixColSum[i]);
        }
        // 5.4 | Matrix total sum
        printf(" | %3d", matrixTotalSum);

        printf("\n\n");

        // 6.0 | Print Transpose of matrix
        printf("\nTranspose of the matrix:\n");        
        // 6.1 | Matrix transpose header
        printf("              ");
        for (int i = 0; i < matrixTransposeCols; i++) {
            printf("%3c ", ' ');
        }
        printf("%-4s", "  Sum-of-Row");
        // 6.2 | Matrix transpose value sand sum-of-rows
        for (int i = 0; i < matrixTransposeRows; i++) {
            printf("\n              ");
            for (int j = 0; j < matrixTransposeCols; j++) {
                printf("%3d ", matrixTranspose[i][j]);
            }
            printf(" | %3d ", matrixTransposeRowSum[i]);
        }
        // 6.3 | Matrix sum-of-columns
        printf("\n              -------------------------");
        printf("\nSum-of-Column:");
        for (int i = 0; i < matrixTransposeCols; i++) {
            printf("%3d ", matrixTransposeColSum[i]);
        }
        // 6.4 | Matrix transpose total sum
        printf(" | %3d", matrixTransposeTotalSum);

        printf("\n\n");

        return 0;
    }

    // 5.0 | Get upper and lower triangular sums of matrix
    matrixMainDiagonalSum = getMatrixDiagonalSum(matrix, matrixRows);
    matrixUpperTriangularSum = getMatrixUpperTriangularSum(matrix, matrixRows);
    matrixLowerTriangularSum = getMatrixLowerTriangularSum(matrix, matrixRows);
    // 5.1 | Get upper and lower triangular sums of matrix transpose
    matrixTransposeMainDiagonalSum = getMatrixDiagonalSum(matrixTranspose, matrixTransposeRows);
    matrixTransposeUpperTriangularSum = getMatrixUpperTriangularSum(matrixTranspose, matrixTransposeRows);
    matrixTransposeLowerTriangularSum = getMatrixLowerTriangularSum(matrixTranspose, matrixTransposeRows);


    // 6.0 | Print Original Matrix
    printf("\nOriginal Matrix: Rectangular Matrix\n");
    // 6.1 | Matrix Header
    printf("              ");
    for (int i = 0; i < matrixCols; i++) {
        printf("%3c ", ' ');
    }
    printf("%-4s", "  Sum-of-Row");
    // 6.2 | Matrix values and sum-of-rows
    for (int i = 0; i < matrixRows; i++) {
        printf("\n              ");
        for (int j = 0; j < matrixCols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf(" | %3d ", matrixRowSum[i]);
    }
    // 6.3 | Matrix sum-of-columns
    printf("\n              -------------------------");
    printf("\nSum-of-Column:");
    for (int i = 0; i < matrixCols; i++) {
        printf("%3d ", matrixColSum[i]);
    }
    // 6.4 | Matrix total sum
    printf(" | %3d", matrixTotalSum);

    printf("\n\nSum of the Main Diagonal: %d", matrixMainDiagonalSum);
    printf("\nSum of the Upper Triangular Matrix: %d", matrixUpperTriangularSum);
    printf("\nSum of the Lower Triangular Matrix: %d", matrixLowerTriangularSum);

    printf("\n\n***********************************************************");

    // 7.0 | Print Transpose of matrix
    printf("\nTranspose of the matrix:\n");        
    // 7.1 | Matrix transpose header
    printf("              ");
    for (int i = 0; i < matrixTransposeCols; i++) {
        printf("%3c ", ' ');
    }
    printf("%-4s", "  Sum-of-Row");
    // 7.2 | Matrix transpose value sand sum-of-rows
    for (int i = 0; i < matrixTransposeRows; i++) {
    printf("\n              ");
    for (int j = 0; j < matrixTransposeCols; j++) {
        printf("%3d ", matrixTranspose[i][j]);
    }
    printf(" | %3d ", matrixTransposeRowSum[i]);
    }
    // 7.3 | Matrix sum-of-columns
    printf("\n              -------------------------");
    printf("\nSum-of-Column:");
    for (int i = 0; i < matrixTransposeCols; i++) {
       printf("%3d ", matrixTransposeColSum[i]);
    }
    // 7.4 | Matrix transpose total sum
    printf(" | %3d", matrixTransposeTotalSum);

    printf("\n\nSum of the Main Diagonal: %d", matrixTransposeMainDiagonalSum);
    printf("\nSum of the Upper Triangular Matrix: %d", matrixTransposeUpperTriangularSum);
    printf("\nSum of the Lower Triangular Matrix: %d", matrixTransposeLowerTriangularSum);

    printf("\n\n");

    return 0;
}