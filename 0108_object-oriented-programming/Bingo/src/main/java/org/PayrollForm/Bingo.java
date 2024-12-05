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
    private final int[][] cardNumbers = new int[BINGO_SIZE][BINGO_SIZE];
    private final JLabel[][] cardNumberLabels = new JLabel[BINGO_SIZE][BINGO_SIZE];

    private boolean isRolling = false;
    private int multipleRollsCount = 5;
    private JLabel[] resultLabels =  new JLabel[multipleRollsCount];
    private JFrame mainGUIFrame;
//    private JLabel resultLabel;
    private JPanel rolledPanel;
    private JButton rollSingleNumberBtn;
    private JButton rollMultipleNumberBtn;
    private Set<Integer> rolledNumbers = new HashSet<>();
    private final String GUI_TITLE = "Canonizado's Bingo Game!";
    private final String BINGO_HEADER = "BINGO";
    private final Font headerFont = new Font("Arial", Font.BOLD, 32);
    private final Font numGridFont = new Font("Arial", Font.PLAIN, 24);
    private final Font rolledFont = new Font("Arial", Font.PLAIN, 18);
    private final Font controlsFont = new Font("Arial", Font.PLAIN, 18);

    public Bingo() {
        generateCard(this.cardNumbers);
        initializeGUI();
    }

    private void generateCard(int[][] card) {
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

    private void rollNumber(JLabel resultLabel) {
        final int[] randomNumber = new int[1];

        Timer shuffleTimer = new Timer(50, e -> {
            do {
                randomNumber[0] = RANDOM.nextInt(MAX_NUMBER) + 1;
            } while (rolledNumbers.contains(randomNumber[0]));
            resultLabel.setText(getNumberCode(randomNumber[0]));
        });
        shuffleTimer.start();

        Timer stopTimer = new Timer(500, e -> {
            shuffleTimer.stop();
            rolledNumbers.add(randomNumber[0]);
            resultLabel.setText(getNumberCode(randomNumber[0]));
            markNumber(randomNumber[0]);
            numberOfRolls++;
            boolean isWinner = isWinningCard();
            if (isWinner) {
                rollSingleNumberBtn.setEnabled(false);
                rollMultipleNumberBtn.setEnabled(false);
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
                }
            }
        }
    }

    private boolean checkWinningLine(int[] line) {
        for (int i = 0; i < line.length; i++) {
            if (line[i] != -1 && line[i] != 0) {
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

    private void resetCard() {
        generateCard(this.cardNumbers);
        mainGUIFrame.removeAll();
        mainGUIFrame.revalidate();
        mainGUIFrame.repaint();
        mainGUIFrame.setVisible(false);

        initializeGUI();
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

        JPanel rolled = new JPanel();
        rolled.setLayout(new BoxLayout(rolled, BoxLayout.X_AXIS));
        rolled.setBorder(BorderFactory.createEmptyBorder(0, 50, 0, 0));
        rolled.setBackground(Color.white);
        rolled.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_ROLLED_HEIGHT));
        JLabel rolledHeader = new JLabel();
        rolledHeader.setText("Rolled:  ");
        rolledHeader.setFont(rolledFont);
        rolledHeader.setHorizontalAlignment(SwingConstants.RIGHT);
        rolledHeader.setVerticalAlignment(SwingConstants.CENTER);
        rolled.add(rolledHeader);

        JPanel rolledResults = new JPanel(new GridLayout(0,multipleRollsCount + 1, 0, 0));
        rolledResults.setBackground(Color.white);
        rolledResults.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_ROLLED_HEIGHT));
        for (int i = 0; i < multipleRollsCount; i++) {
            JLabel rolledResult = new JLabel();
            rolledResult.setText("");
            rolledResult.setFont(rolledFont);
            rolledResult.setHorizontalAlignment(SwingConstants.LEFT);
            rolledResult.setVerticalAlignment(SwingConstants.CENTER);
            resultLabels[i] = rolledResult;
            rolledResults.add(rolledResult);
        }
        rolled.add(rolledResults);
        rolledPanel = rolled;

        JPanel controls = new JPanel(new GridLayout(0,3));
        controls.setBackground(Color.green);
        controls.setMaximumSize(new Dimension(GUI_WIDTH, PANEL_CONTROLS_HEIGHT));

        JButton newCardBtn = new JButton("Get new card");
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
            public void mouseClicked(MouseEvent e) {
                resetCard();
            }
        });

        JButton rollSingleBtn = new JButton("Roll 1 number");
        rollSingleBtn.setFont(controlsFont);
        rollSingleBtn.setBackground(Color.white);
        rollSingleBtn.setForeground(Color.black);
        rollSingleBtn.setBorder(BorderFactory.createMatteBorder(2, 0, 2, 1, Color.BLACK));
        rollSingleBtn.setFocusPainted(false);
        rollSingleBtn.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        rollSingleBtn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent event) {
                if (rollSingleBtn.isEnabled()) {
                    rollSingleNumberBtn.setBackground(Color.black);
                    rollSingleNumberBtn.setForeground(Color.white);
                }
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                    rollSingleNumberBtn.setBackground(Color.white);
                    rollSingleNumberBtn.setForeground(Color.black);
            }
            public void mouseClicked(MouseEvent e) {
                if (rollSingleBtn.isEnabled()) {
                    rollNumber(resultLabels[0]);
                }
            }
        });rollSingleBtn.setFont(controlsFont);

        JButton rollMultipleBtn = new JButton("Roll " + multipleRollsCount + " numbers");
        rollMultipleBtn.setFont(controlsFont);
        rollMultipleBtn.setBackground(Color.white);
        rollMultipleBtn.setForeground(Color.black);
        rollMultipleBtn.setBorder(BorderFactory.createMatteBorder(2, 0, 2, 1, Color.BLACK));
        rollMultipleBtn.setFocusPainted(false);
        rollMultipleBtn.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        rollMultipleBtn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent event) {
                if (rollMultipleBtn.isEnabled()) {
                    rollMultipleNumberBtn.setBackground(Color.black);
                    rollMultipleNumberBtn.setForeground(Color.white);
                }
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                    rollMultipleNumberBtn.setBackground(Color.white);
                    rollMultipleNumberBtn.setForeground(Color.black);
            }
            public void mouseClicked(MouseEvent e) {
                if (rollMultipleBtn.isEnabled()) {
                    for (int i = 0; i < multipleRollsCount; i++) {
                        rollNumber(resultLabels[i]);
                    }
                }
            }
        });

        rollSingleNumberBtn = rollSingleBtn;
        rollMultipleNumberBtn = rollMultipleBtn;
        controls.add(rollSingleBtn);
        controls.add(rollMultipleBtn);
        controls.add(newCardBtn);

        frame.add(header);
        frame.add(numGrid);
        frame.add(rolled);
        frame.add(controls);
        frame.setVisible(true);
        mainGUIFrame = frame;
    }
}
