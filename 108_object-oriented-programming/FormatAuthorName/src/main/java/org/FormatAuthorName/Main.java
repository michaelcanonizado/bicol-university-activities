package org.FormatAuthorName;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        // Minimum of 1 part: last name
        // Maximum of 3 parts: First, Middle, Last
        // Middle name is optional

        // Only the first letter of eahc part should be capital
        // First and Second names should be the initials followed by a '.': E.g: lady agusTa -> L. Agusta
        // Each character of the name should be a lower or upper case. No other numerical characters or symbols.

        File inputFile = new File("input.in");
        Scanner scanner = new Scanner(inputFile);

        String name;

        while(scanner.hasNext()) {
            name = scanner.nextLine();
            name = name.trim().toLowerCase();

            int indexOfStartOfWord = 0;

            for (int i = 0; i < name.length(); i++) {
                if (name.charAt(i) == ' ') {
                    System.out.print(Character.toUpperCase(name.charAt(indexOfStartOfWord)) + ". ");
                    indexOfStartOfWord = i + 1;
                } else if (i == name.length() - 1) {
                    System.out.print(Character.toUpperCase(name.charAt(indexOfStartOfWord)) + name.substring(indexOfStartOfWord + 1));
                }
            }
            System.out.println();
        }
    }
}