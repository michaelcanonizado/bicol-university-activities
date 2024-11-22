package org.PayrollForm;

import java.util.HashSet;
import java.util.Random;

public class Bingo {
    private final int SIZE = 5;
    private final int MAX_NUMBER = 75;
    private final Random RANDOM = new Random();
    private int[][] bingoCard;

    private int[][] generateBingoCard() {
        int[][] card = new int[SIZE][SIZE];

        for (int col = 0; col < SIZE; col++) {
            int min = (col * 15) + 1;
            int max = min + 14;
            HashSet<Integer> generatedNumsInCol = new HashSet<>();

            for (int row = 0; row < SIZE; row++) {
                if (row == 2 && col == 2) {
                    card[row][col] = 0;
                } else {
                    int number;
                    do {
                        number = RANDOM.nextInt(max - min + 1) + min;
                    } while (generatedNumsInCol.contains(number));
                    generatedNumsInCol.add(number);
                    card[row][col] = number;
                }
            }

        }
        return card;
    }
}
