package org.PayrollForm;

import javax.swing.*;
import java.awt.*;
import java.util.HashSet;
import java.util.Random;

public class Bingo {
    private final int BINGO_SIZE = 5;
    private final int MAX_NUMBER = 75;
    private final Random RANDOM = new Random();
    private final int GUI_WIDTH = 500;
    private final int PANEL_HEADER_HEIGHT = 100;
    private final int PANEL_NUM_GRID_HEIGHT = GUI_WIDTH;
    private final int PANEL_CONTROLS_HEIGHT = 100;
    private final int GUI_HEIGHT = PANEL_HEADER_HEIGHT + PANEL_NUM_GRID_HEIGHT + PANEL_CONTROLS_HEIGHT;
    private int[][] card;

    public Bingo() {
        this.card = generateCard();
        initializeGUI();
    }

    private int[][] generateCard() {
        int[][] card = new int[BINGO_SIZE][BINGO_SIZE];

        for (int row = 0; row < BINGO_SIZE; row++) {
            int min = (row * 15) + 1;
            int max = min + 14;
            HashSet<Integer> generatedNumsInCol = new HashSet<>();

            for (int col = 0; col < BINGO_SIZE; col++) {
                if (col == (BINGO_SIZE / 2) && row == (BINGO_SIZE / 2)) {
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

    public void displayCard() {
        System.out.println(" B  I  N  G  O ");
        for (int row = 0; row < BINGO_SIZE; row++) {
            for (int col = 0; col < BINGO_SIZE; col++) {
                System.out.printf("%2d ",card[row][col]);
            }
            System.out.println();
        }
    }

    private void initializeGUI() {
        JFrame frame = new JFrame();
        frame.setTitle("Canonizado's Bingo Game!");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setSize(GUI_WIDTH, GUI_HEIGHT);

        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        JPanel header = new JPanel();
        header.setBackground(Color.blue);
        header.setPreferredSize(new Dimension(GUI_WIDTH, PANEL_HEADER_HEIGHT));
        header.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_HEADER_HEIGHT));

        JPanel numGrid = new JPanel(new GridLayout(BINGO_SIZE, BINGO_SIZE, 0, 0));
        numGrid.setBackground(Color.red);
        numGrid.setPreferredSize(new Dimension(GUI_WIDTH, PANEL_NUM_GRID_HEIGHT));
        numGrid.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_NUM_GRID_HEIGHT));
        for (int row = 0; row < BINGO_SIZE; row++) {
            for (int col = 0; col < BINGO_SIZE; col++) {
                JButton button = new JButton();
                if (card[row][col] == 0) {
                    button.setText("FREE");
                } else {
                    button.setText(String.valueOf(card[row][col]));
                }
                button.setEnabled(false);
                numGrid.add(button);
            }
        }

        JPanel controls = new JPanel();
        controls.setBackground(Color.green);
        controls.setPreferredSize(new Dimension(GUI_WIDTH, PANEL_CONTROLS_HEIGHT));
        controls.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_CONTROLS_HEIGHT));

        System.out.println(GUI_WIDTH);
        System.out.println(GUI_HEIGHT);
        System.out.println(PANEL_HEADER_HEIGHT);
        System.out.println(PANEL_NUM_GRID_HEIGHT);
        System.out.println(PANEL_CONTROLS_HEIGHT);

        frame.add(header);
        frame.add(numGrid);
        frame.add(controls);
        frame.setVisible(true);
    }
}
