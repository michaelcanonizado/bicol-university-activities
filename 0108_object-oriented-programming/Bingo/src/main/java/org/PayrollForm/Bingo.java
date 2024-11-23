package org.PayrollForm;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Bingo {
    private final int BINGO_SIZE = 5;
    private final int MAX_NUMBER = 75;
    private int numberOfRolls = 0;
    private final Random RANDOM = new Random();
    private final int[][] cardNumbers;
    private final JLabel[][] cardNumberLabels = new JLabel[BINGO_SIZE][BINGO_SIZE];
    private JLabel resultLabel;
    private JPanel rolledPanel;
    private JButton rollNumberBtn;
    private Set<Integer> rolledNumbers = new HashSet<>();
    private final String GUI_TITLE = "Canonizado's Bingo Game!";
    private final String BINGO_HEADER = "BINGO";
    private final Font headerFont = new Font("Arial", Font.BOLD, 32);
    private final Font numGridFont = new Font("Arial", Font.PLAIN, 24);
    private final Font rolledFont = new Font("Arial", Font.PLAIN, 24);
    private final Font controlsFont = new Font("Arial", Font.PLAIN, 24);

    public Bingo() {
        this.cardNumbers = generateCard();
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
                System.out.printf("%2d ", cardNumbers[row][col]);
            }
            System.out.println();
        }
    }

    private char determineNumberColumn(int number) {
        char[] columns = {'B','I','N','G','O'};
        int columnIndex = (number - 1) / 15;
        return columns[columnIndex];
    }
    private String getNumberCode(int number) {
        char column = determineNumberColumn(number);
        StringBuilder code = new StringBuilder();
        code.append(column);
        code.append(number);
        return code.toString();
    }

    private void rollNumber() {
        final int[] randomNumber = new int[1];

        Timer shuffleTimer = new Timer(50, e -> {
            do {
                randomNumber[0] = RANDOM.nextInt(MAX_NUMBER) + 1;
            } while (rolledNumbers.contains(randomNumber[0]));
            resultLabel.setText(getNumberCode(randomNumber[0]));
        });
        shuffleTimer.start();

        Timer stopTimer = new Timer(100, e -> {
            shuffleTimer.stop();
            rolledNumbers.add(randomNumber[0]);
            resultLabel.setText(getNumberCode(randomNumber[0]));
            markNumber(randomNumber[0]);
            numberOfRolls++;
            boolean isWinner = isWinningCard();
            if (isWinner) {
                rollNumberBtn.setEnabled(false);
                rolledPanel.removeAll();
                rolledPanel.setLayout(new BorderLayout());
                JLabel winnerLabel = new JLabel("You have won! Number of rolls: " + numberOfRolls, SwingConstants.CENTER);
                winnerLabel.setFont(rolledFont);
                winnerLabel.setHorizontalAlignment(SwingConstants.CENTER);
                winnerLabel.setVerticalAlignment(SwingConstants.CENTER);

                rolledPanel.add(winnerLabel, BorderLayout.CENTER);
                rolledPanel.revalidate();
                rolledPanel.repaint();
            }

            System.out.println("Rolled: " + getNumberCode(randomNumber[0]));
            System.out.println("Is Winner: " + isWinner);

        });

        stopTimer.setRepeats(false);
        stopTimer.start();
    }

    private void markNumber(int number) {
        for (int row = 0; row < BINGO_SIZE; row++) {
            for (int col = 0; col < BINGO_SIZE; col++) {
                if (cardNumbers[row][col] == number) {
                    cardNumbers[row][col] = -1;
                    cardNumberLabels[row][col].setBackground(Color.red);
                    System.out.println("Label: " +cardNumberLabels[row][col].getText()
                    + " Row: " + row + " Col: " + col + " | " + cardNumbers[row][col]);
                }
            }
        }
    }

    private boolean checkWinningLine(int[] line) {
        for (int i = 0; i < line.length; i++) {
            if (line[i] != -1) {
                return false;
            }
        }
        return true;
    }
    private boolean isWinningCard() {
        // Check rows
        for (int row = 0; row < BINGO_SIZE; row++) {
            if (checkWinningLine(cardNumbers[row])) {
                return true;
            }
        }

        // Check columns
        for (int col = 0; col < BINGO_SIZE; col++) {
            int[] column = new int[BINGO_SIZE];
            for (int row = 0; row < BINGO_SIZE; row++) {
                column[row] = cardNumbers[row][col];
            }
            if (checkWinningLine(column)) {
                return true;
            }
        }

        // Check diagonals
        int[] diagonal1 = new int[BINGO_SIZE];
        int[] diagonal2 = new int[BINGO_SIZE];
        for (int i = 0; i < BINGO_SIZE; i++) {
            diagonal1[i] = cardNumbers[i][i];
            diagonal2[i] = cardNumbers[i][BINGO_SIZE - i - 1];
        }
        return checkWinningLine(diagonal1) || checkWinningLine(diagonal2);
    }

    private void initializeGUI() {
        final int GUI_WIDTH = 500;
        final int PANEL_HEADER_HEIGHT = 100;
        final int PANEL_NUM_GRID_HEIGHT = GUI_WIDTH;
        final int PANEL_ROLLED_HEIGHT = 50;
        final int PANEL_CONTROLS_HEIGHT = 100;
        final int GUI_HEIGHT =
                PANEL_HEADER_HEIGHT +
                PANEL_NUM_GRID_HEIGHT +
                PANEL_ROLLED_HEIGHT +
                PANEL_CONTROLS_HEIGHT;

        JFrame frame = new JFrame();
        frame.setTitle(GUI_TITLE);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setBackground(Color.black);
        frame.setSize(GUI_WIDTH, GUI_HEIGHT);

        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        JPanel header = new JPanel(new GridLayout(0, BINGO_HEADER.length()));
        header.setBackground(Color.black);
        header.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_HEADER_HEIGHT));
        for (char headerChar : BINGO_HEADER.toCharArray()) {
            JLabel label = new JLabel();
            label.setText(Character.toString(headerChar).toUpperCase());
            label.setFont(headerFont);
            label.setForeground(Color.white);
            label.setVerticalAlignment(SwingConstants.CENTER);
            label.setHorizontalAlignment(SwingConstants.CENTER);
            header.add(label);
        }

        JPanel numGrid = new JPanel(new GridLayout(BINGO_SIZE, BINGO_SIZE, 0 ,0));
        numGrid.setBorder(new LineBorder(Color.black, 2));
        numGrid.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_NUM_GRID_HEIGHT));
        for (int row = 0; row < BINGO_SIZE; row++) {
            for (int col = 0; col < BINGO_SIZE; col++) {
                JLabel label = new JLabel();
                label.setOpaque(true);
                if (cardNumbers[row][col] == 0) {
                    label.setText("FREE");
                } else {
                    label.setText(String.valueOf(cardNumbers[row][col]));
                }
                label.setFont(numGridFont);
                label.setBackground(Color.white);
                label.setForeground(Color.black);
                label.setVerticalAlignment(SwingConstants.CENTER);
                label.setHorizontalAlignment(SwingConstants.CENTER);
                label.setBorder(new LineBorder(Color.black, 2));
                numGrid.add(label);
                cardNumberLabels[row][col] = label;
            }
        }

        JPanel rolled = new JPanel(new GridLayout(0,2, 10, 0));
        rolled.setBackground(Color.white);
        rolled.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_ROLLED_HEIGHT));
        JLabel rolledHeader = new JLabel();
        JLabel rolledResult = new JLabel();
        rolledHeader.setText("Rolled:");
        rolledResult.setText("");
        rolledHeader.setFont(rolledFont);
        rolledResult.setFont(rolledFont);
        rolledHeader.setHorizontalAlignment(SwingConstants.RIGHT);
        rolledResult.setHorizontalAlignment(SwingConstants.LEFT);
        rolledHeader.setVerticalAlignment(SwingConstants.CENTER);
        rolledResult.setVerticalAlignment(SwingConstants.CENTER);
        resultLabel = rolledResult;
        rolled.add(rolledHeader);
        rolled.add(rolledResult);
        rolledPanel = rolled;

        JPanel controls = new JPanel(new GridLayout(0,2));
        controls.setBackground(Color.green);
        controls.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_CONTROLS_HEIGHT));
        JButton newCardBtn = new JButton("Get new card");
        JButton rollBtn = new JButton("Roll number");

        newCardBtn.setFont(controlsFont);
        newCardBtn.setBackground(Color.white);
        newCardBtn.setForeground(Color.black);
        newCardBtn.setBorder(BorderFactory.createMatteBorder(2, 1, 2, 0, Color.BLACK));
        newCardBtn.setFocusPainted(false);
        newCardBtn.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        newCardBtn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent event) {
                newCardBtn.setBackground(Color.black);
                newCardBtn.setForeground(Color.white);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                newCardBtn.setBackground(Color.white);
                newCardBtn.setForeground(Color.black);
            }
        });

        rollBtn.setFont(controlsFont);
        rollBtn.setBackground(Color.white);
        rollBtn.setForeground(Color.black);
        rollBtn.setBorder(BorderFactory.createMatteBorder(2, 0, 2, 1, Color.BLACK));
        rollBtn.setFocusPainted(false);
        rollBtn.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        rollBtn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent event) {
                rollNumberBtn.setBackground(Color.black);
                rollNumberBtn.setForeground(Color.white);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                rollNumberBtn.setBackground(Color.white);
                rollNumberBtn.setForeground(Color.black);
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                rollNumber();
            }
        });

        rollNumberBtn = rollBtn;
        controls.add(rollBtn);
        controls.add(newCardBtn);

        frame.add(header);
        frame.add(numGrid);
        frame.add(rolled);
        frame.add(controls);
        frame.setVisible(true);
    }
}
