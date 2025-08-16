// Michael Canonizado and Cid Chusuey
// BSCS-1A
// This program takes in 5 values from a file and calculates their respective square and square root, and the sum and average of the 5 numbers.

//
// Accomplished on 04/10/23 (DD/MM/YY)
// SCORE: 98/100
// -2 Points becuase of "unesssary" storage of input file name in a variable.

// Neccessary libraries
#include <stdio.h>
#include <math.h>


int main() {
	char name[20];
	int n1,n2,n3,n4,n5;
	float sq1,sq2,sq3,sq4,sq5;
	int s1,s2,s3,s4,s5;
	int sum;
	float average;
	
	// Read txt file
	char inputFileName[] = "prac1.in";
	FILE *inputFP;
	inputFP = fopen(inputFileName,"rt");
	
	// Check if input file found
	if (inputFP == NULL) {
		printf("\n%s not found! Please Try again\n", inputFileName);
		return 1;
	}
	
	// Get input from user
	printf("Please input your name: ");
	scanf("%s", name);
	// Greet user
	printf("\nGood day \"%s\"!",name);
	
	// store values
	fscanf(inputFP, "%d", &n1);
	fscanf(inputFP, "%d", &n2);
	fscanf(inputFP, "%d", &n3);
	fscanf(inputFP, "%d", &n4);
	fscanf(inputFP, "%d", &n5);
	
	// Close file pointer immediately after reading
	fclose(inputFP);
	
	if (!n1 || !n2 || !n3 || !n4 || !n5) {
		printf(" Please make sure there are 5 numbers in your input file. Please run program again!\n");
		return 1;
	}
	
	// compute values
	// Square
	s1 = n1 * n1;
	s2 = n2 * n2;
	s3 = n3 * n3;
	s4 = n4 * n4;
	s5 = n5 * n5;
	
	// Square root
	sq1 = sqrt(n1);
	sq2 = sqrt(n2);
	sq3 = sqrt(n3);
	sq4 = sqrt(n4);
	sq5 = sqrt(n5);
	
	// Sum
	sum = n1 + n2 + n3 + n4 + n5;
	
	// Average
	average = sum / 5.0;
	
	// output to terminal
	printf("\n------------------------------------");
	printf("\n|%3c   |%10s |%14s |",'N', "Square(N)", "SquareRoot(N)");
	printf("\n------------------------------------");
	printf("\n|%5d |%10d |%14.4f |", n1, s1, sq1);
	printf("\n|%5d |%10d |%14.4f |", n2, s2, sq2);
	printf("\n|%5d |%10d |%14.4f |", n3, s3, sq3);
	printf("\n|%5d |%10d |%14.4f |", n4, s4, sq4);
	printf("\n|%5d |%10d |%14.4f |", n5, s5, sq5);
	
	printf("\n\nThe sum of the five numbers is %d and their average is %.2f\n", sum, average);
	
	return 0;
}

