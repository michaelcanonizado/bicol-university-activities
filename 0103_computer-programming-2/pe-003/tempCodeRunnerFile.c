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