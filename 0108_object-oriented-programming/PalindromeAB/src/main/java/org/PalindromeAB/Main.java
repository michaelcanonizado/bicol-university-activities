package org.PalindromeAB;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        File inputFile = new File("input.in");
        Scanner scanner = new Scanner(inputFile);

        // get number of tests
        int numOfTests = Integer.parseInt(scanner.nextLine().trim());

        for (int i = 0; i < numOfTests; i++) {
            String line = scanner.nextLine();
            String[] numbers = line.split(" ");

            int x = Integer.parseInt(numbers[0]);
            int y = Integer.parseInt(numbers[1]);
            boolean isXEven = x % 2 == 0;
            boolean isYEven = y % 2 == 0;

            // Invalid Pair
            if (isXEven == false && isYEven == false) {
                System.out.println("-1");
                continue;
            }

//            System.out.print(x + " " + y + ": ");

            char firstChar = !isXEven && isYEven ? 'b' : 'a';
            char secondChar = !isXEven && isYEven ? 'a' : 'b';
            int firstCount = !isXEven && isYEven ? y : x;
            int secondCount = !isXEven && isYEven ? x : y;
            for (int j = 1; j <= 2; j++) {

                for (int k = 0; k < firstCount/2; k++) {
                    System.out.print(firstChar);
                }
                for (int k = 0; k < secondCount/2; k++) {
                    System.out.print(secondChar);
                }
                if (!isXEven) {
                    System.out.print("a");
                }
                if (!isYEven) {
                    System.out.print("b");
                }
                for (int k = 0; k < secondCount/2; k++) {
                    System.out.print(secondChar);
                }
                for (int k = 0; k < firstCount/2; k++) {
                    System.out.print(firstChar);
                }

                System.out.println("");
                char tempChar = firstChar;
                firstChar = secondChar;
                secondChar = tempChar;

                int tempCount = firstCount;
                firstCount = secondCount;
                secondCount = tempCount;
            }
        }

    }
}