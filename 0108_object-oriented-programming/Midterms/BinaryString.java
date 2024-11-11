import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;

public class BinaryString {
    public static void main(String args[]) throws FileNotFoundException {
        File inputFile = new File("BinaryString.in");
        Scanner scanner = new Scanner(inputFile);
        
        int numOfTestCases = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < numOfTestCases; i++) {
            String firstLine[] = scanner.nextLine().split(" ");
            int strLength = Integer.parseInt(firstLine[0]); 
            int XRate = Integer.parseInt(firstLine[1]); 
            int YRate = Integer.parseInt(firstLine[2]);
            String binaryStr = scanner.nextLine();
            
            int numOfZero = 0;
            int numOfOne = 0;
            int minRate = 0;
            int totalTax = 0;
            
            for (int j = 0; j < strLength - 1; j++) {
                if (binaryStr.charAt(j) == '0') {
                    numOfZero++;
                }
                
                if (binaryStr.charAt(j) == '1') {
                    numOfOne++;
                }
            }
                
            if (numOfZero > 0 && numOfOne > 0) {
                minRate = Integer.min(XRate, YRate);
                totalTax = minRate;
            }
            
            // System.out.println(binaryStr + " " +  XRate +"|"+ YRate + " | 10:" + numOfZero+ " 01:" + numOfOne + " | total:" + totalTax);
            System.out.println(totalTax);
        }
    }
}