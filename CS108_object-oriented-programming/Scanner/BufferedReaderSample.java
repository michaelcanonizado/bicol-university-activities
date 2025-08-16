import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;


public class BufferedReaderSample{
	public static void main(String args[])
	{
		String name = "";
		String mathGrade = "";
		String englishGrade = "";
		double average = 0.0;

		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

		try{
			System.out.println("Please Enter Your Name : ");
			name = input.readLine();
			System.out.println("Please Enter Your Math Grade ");
			mathGrade = input.readLine();
			System.out.println("Please Enter Your English Grade ");
			englishGrade = input.readLine();

		}catch(IOException e){
			
			System.out.println("Error in Input!");

		}
		average = (Double.parseDouble(mathGrade) + Double.parseDouble(englishGrade)) / 2;

		System.out.println("Your name is " + name);
		System.out.println("Your average grade is " + average);

	}
}