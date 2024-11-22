package org.PayrollForm;

import java.util.HashSet;
import java.util.Random;

public class Bingo {
    private final int SIZE = 5;
    private final int MAX_NUMBER = 75;
    private final Random RANDOM = new Random();
    private int[][] card;

    public Bingo() {
        this.card = generateCard();
    }

    private int[][] generateCard() {
        int[][] card = new int[SIZE][SIZE];

        for (int row = 0; row < SIZE; row++) {
            int min = (row * 15) + 1;
            int max = min + 14;
            HashSet<Integer> generatedNumsInCol = new HashSet<>();

            for (int col = 0; col < SIZE; col++) {
                if (col == (SIZE / 2) && row == (SIZE / 2)) {
                    card[col][row] = 0;
                } else {
                    int number;
                    do {
                        number = RANDOM.nextInt(max - min + 1) + min;
                    } while (generatedNumsInCol.contains(number));
                    generatedNumsInCol.add(number);
                    card[col][row] = number;
                }
            }

        }
        return card;
    }
}
