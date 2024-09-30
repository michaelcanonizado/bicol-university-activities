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
            // Remove '-' separating the characters
            encodedPIN = encodedPIN.replace("-","");

            // Iterate through the string and replace the necessary characters
            for (int i = 0; i < encodedPIN.length(); i++) {
                // If character can be parsed through Integer.parseInt(), convert it to integer and output it.
                try {
                    System.out.print("[" + Integer.parseInt(String.valueOf(encodedPIN.charAt(i))) + "]");
                }
                // Else if the current character can't the parsed, offset the ASCII value then output it.
                catch (NumberFormatException e) {
                    System.out.print("[" + ((int)encodedPIN.charAt(i) - 55) + "]");
                }

            }
            System.out.println();
        }
    }
}