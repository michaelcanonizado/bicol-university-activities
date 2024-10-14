package org.PalindromeAB;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        File inputFile = new File("input.in");
        Scanner scanner = new Scanner(inputFile);

        int numOfTests = Integer.parseInt(scanner.nextLine().trim());
        System.out.println(numOfTests);
        for (int i = 0; i < numOfTests; i++) {
            String line = scanner.nextLine();
            String[] numbers = line.split(" ");
            int x = Integer.parseInt(numbers[0]);
            int y = Integer.parseInt(numbers[1]);

            System.out.printf("x: %d, y: %d\n", x, y);
//            System.out.println(line);
        }

    }
}