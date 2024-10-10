import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class ScannerSample{
	public static void main(String[] args) throws Exception{
	
	File f = new File("sample.in");
	Scanner scan = new Scanner(f);

	int value = 0;

	while(scan.hasNext()){
		value = scan.nextInt();
		System.out.println(value);
		for(int i=0; i<value; i++)
		{
			for(int j=0; j<=i; j++)
			{
				System.out.print("*");
			}
		System.out.println();
		}
	}
	}
}