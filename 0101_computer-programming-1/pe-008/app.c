// Michael Xavier Canonizado | BSCS-1A
// This program asks the user to input 2 integers (centavos and hours) to calculate the wage rate using the given formula

#include <stdio.h>

// User defined function to check if the parameter inputted is a prime number
int isPrime(int num) {
    // If number is less than opr equal to 1, return false (0)
    if (num <= 1) {
        return 0;
    }
    // Loop through to see if the number has a factor other than itself or 1
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    // if no factor/divisor was found, return true (1)
    return 1;
}

// User defined function to check if the parameter inputted is a perfect number
int isPerfect(int num) {
    // If nunmber inputted is less than 1, return false (0)
    if (num < 1) {
        return 0;
    }
    int sum = 0;
    int counter = 1;
    // Loop throught the number, checking for factors, and if a factor is found, add it to the sum accumilator.
    while (counter < num) {
        if (num % counter == 0) {
            sum += counter;
        }
        counter++;
    }
    // Compare if the accumilated sum is equal to the number in the parameter. if yes return false (0) else return true (1)
    if (sum != num) {
        return 0;
    } else {
        return 1;
    }
}

int main(void) {
    // Boolean variable to hold the status of isPrime and isPerfect
    int intIsPrime, intIsPerfect;
    // Variable to hold the inputted integer
    int integer;


    // Contiously ask user
     do {

        printf("\nEnter a positive integer(Ctrl-Z to end): ");
        
        if (scanf("%d", &integer) == EOF) {
            printf(" End of program. Thanks!\n\n");
            break;
        }

        if (integer > 0) {
            intIsPrime = isPrime(integer);
            intIsPerfect = isPerfect(integer);
            if (intIsPrime == 1) {
                printf(" prime: YES\n");
            } else {
                printf(" prime: NO\n");
            }
            if (intIsPerfect == 1) {
                printf(" perfect: YES\n");
            } else {
                printf(" perfect: NO\n");
            }   
        } else {
            printf(" please enter a positive integer.\n");
        }       
     } while (1);
     
    return 1;
}