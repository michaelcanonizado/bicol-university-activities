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

        // Get test values and run tests
        for (int i = 0; i < numOfTests; i++) {
            // Get x and y from each line
            String line = scanner.nextLine();
            String[] numbers = line.split(" ");
            int x = Integer.parseInt(numbers[0]);
            int y = Integer.parseInt(numbers[1]);

            // Check if x and y are even or not
            boolean isXEven = x % 2 == 0;
            boolean isYEven = y % 2 == 0;

            // If invalid pair, print '-1' and continue
            if (isXEven == false && isYEven == false) {
                System.out.println("-1");
                continue;
            }

            /*
            *
            * Conditions to pass the tests:
            * 1) If both x and y are odd, invalid input
            * 2) x and y will be halved to print 'a's and 'b's,
            *    if either x or y is odd, half it and print 1 'a'
            *    or 'b' in the middle
            * 3) Since only 2 outputs are expected, the first output
            *    will have half of 'a'. Then in the second half, 'b'
            *    will be next. E.g:
            *    2 4 => 1st: abbbba, 2nd: bbaabb
            * 4) 'a's will always take priority unless x is odd. E.g:
            *    3 4 => 1st: bbaaabb, 2nd: abbabba
            *    4 3 => 1st: aabbbaa, 2nd: baabaab
            *
            * Algorithm:
            * 1) Determine which character and how many of them to print
            * 2) Print them for the 1st iteration
            * 3) Swap the characters and how many to print
            * 2) Print them for the 2nd iteration
            *
            */
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