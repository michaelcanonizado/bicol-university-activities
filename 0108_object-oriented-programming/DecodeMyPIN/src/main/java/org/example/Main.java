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
            encodedPIN = scanner.nextLine();
            System.out.println(encodedPIN);
        }
    }
}