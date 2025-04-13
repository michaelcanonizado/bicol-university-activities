import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;

class BoringString
{
	   public static void main(String args[]) throws FileNotFoundException {
        File inputFile = new File("BoringString.in");
        Scanner scanner = new Scanner(inputFile);
        
        int numOfTestCases = Integer.parseInt(scanner.nextLine());
        
        for (int i = 0; i < numOfTestCases; i++) {
            int strLength = Integer.parseInt(scanner.nextLine());
            String str = scanner.nextLine();
            
            int alphabetSequenceCount[] = new int[26];
            
            
            // Go throuch each letter a-z in the str
            int greatestSequence = 0;
            for (int j = 1; j <= 26; j++) {
                char currLetter = (char)(j+96);
                
                int charSequenceCount[] = new int[10];

                int longestCurrCharSequence = 1;
                
                int charCount = 0;
                
                for (int k = 0; k < strLength-1; k++) {
                    if (str.charAt(k) == currLetter) {
                        
                        if (str.charAt(k) == str.charAt(k+1)) {
                            longestCurrCharSequence++;
                        } else {
                            charSequenceCount[longestCurrCharSequence] += 1;
                            
                            longestCurrCharSequence = 1;
                        }
                        
                        if (k == strLength-2 && str.charAt(k) == str.charAt(k+1)) {
                            charSequenceCount[longestCurrCharSequence] += 1;
                        }
                    }
                }
            
                
                int max = charSequenceCount[0];
                int maxIndex = 0;
                for (int k = 0; k < charSequenceCount.length; k++) {
                    
                    if (max <= charSequenceCount[k] && charSequenceCount[k] > 1) {
                        if (k >= greatestSequence) {
                        max = charSequenceCount[k];
                        maxIndex = k;
                        greatestSequence = k;
                        }
                    }
                }
                
                alphabetSequenceCount[j-1] = greatestSequence;
            }
            
            int max = alphabetSequenceCount[0];
            for (int j = 0; j < alphabetSequenceCount.length; j++) {
                if (max < alphabetSequenceCount[j] ) {
                    max = alphabetSequenceCount[j];
                }  
            }
            
            System.out.println(max);
        }
    }
}