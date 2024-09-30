package org.example;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        File inputFile = new File("input.in");
        Scanner scanner = new Scanner(inputFile);

        String encodedPIN;

        while(scanner.hasNext()) {
            // Read PIN from input.in
            encodedPIN = scanner.nextLine();
            // Remove '-' separating the characters in the string
            encodedPIN = encodedPIN.replace("-","");

            // Iterate through the string and replace the necessary characters
            for (int i = 0; i < encodedPIN.length(); i++) {
                char currentChar = encodedPIN.charAt(i);

                // If character is a digit, output it directly
                if (Character.isDigit(currentChar)) {
                    System.out.print("[" + currentChar + "]");
                }
                // If character is a letter, convert it to the corresponding number
                else if (Character.isLetter(currentChar)) {
                    int value = (int)currentChar - 55;
                    System.out.print("[" + value + "]");
                }
            }
            System.out.println();
        }
    }
}