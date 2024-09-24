package org.MultiDimensionalArray;

public class Main {
    static int[][][][][][][][][][][] multiDimensionalArray = new int[2][2][2][2][2][2][2][2][2][2][3];

    public static void main(String[] args) {
        initializeMultiDimensionalArray();
        printMultiDimensionalArray();
    }

    private static void initializeMultiDimensionalArray() {
        int count = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            for (int n = 0; n < 2; n++) {
                                for (int o = 0; o < 2; o++) {
                                    for (int p = 0; p < 2; p++) {
                                        for (int q = 0; q < 2; q++) {
                                            for (int r = 0; r < 2; r++) {
                                                for (int s = 0; s < 3; s++) {
                                                    multiDimensionalArray[i][j][k][l][m][n][o][p][q][r][s] = count;
                                                    count++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                    }
                }

            }
        }
    }

    private static void printMultiDimensionalArray() {

        System.out.println("---------------------------------------------------------------");
        System.out.println("MultiDimensionalArray Elements:");
        System.out.println("---------------------------------------------------------------");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            for (int n = 0; n < 2; n++) {
                                for (int o = 0; o < 2; o++) {
                                    for (int p = 0; p < 2; p++) {
                                        for (int q = 0; q < 2; q++) {
                                            for (int r = 0; r < 2; r++) {
                                                for (int s = 0; s < 3; s++) {
                                                    System.out.println(" multiDimensionalArray[" + i + "][" + j + "][" + k + "][" + l + "][" + m + "][" + n + "][" + o + "][" + p + "][" + q + "][" + r + "][" + s + "] = " + multiDimensionalArray[i][j][k][l][m][n][o][p][q][r][s]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        System.out.println("---------------------------------------------------------------");
    }

    private static int getElementInMultiDimensionalArray(int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s) {
        return multiDimensionalArray[i][j][k][l][m][n][o][p][q][r][s];
    }
}