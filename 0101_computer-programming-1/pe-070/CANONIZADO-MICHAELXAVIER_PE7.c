// Michael Xavier Canonizado | BSCS-1A
// This program asks the user to input 2 integers (centavos and hours) to calculate the wage rate using the given formula

#include <stdio.h>

int main(void) {
    // Declare multipliers as constants for quick access when rate needs to be changed later on, and for cleaner and organized code
    const float rate1 = 1.0;
    const float rate2 = 1.5;
    const float rate3 = 2.0;

    // Declare user inputs(centavos and hours) as integers as instructed
    int centavos, hours;
    // Declare other variables as floats as it will most likely be decimals
    float pesos,  payInPhp, totalPay;

    // Open file pointer
    FILE *ofp;
    ofp = fopen("payment.txt", "wt");

    // Print headers to txt file
    fprintf(ofp, "Computation of your payment for this week\n");
    fprintf(ofp, "-------------------------------------\n");
    fprintf(ofp, "|%s| %s | %s |\n", "Rate(cts/hr)", "# Hours", "Pay(Pesos)");
    fprintf(ofp, "-------------------------------------\n");

    // Contiously ask the user for input pairs
    while(1) {
        // Promt user for instructions
        printf("Please input a pair of integers(ctrl-D to end): ");
        // If user inputs EOF (Ctrl+D for Linux or Ctrl+Z for Windows) break the loop and output the total to the txt file and terminal
        if (scanf("%d %d", &centavos, &hours) == EOF) {
            printf("This is the end of your input.\n\n");

            printf("TOTAL PAY: %.2f pesos", totalPay);
            fprintf(ofp, "\nTOTAL PAY: PhP %.2f", totalPay);
            break;
        }

        // Convert the centavos input into peso for easier calculation, and so that we wont need to convert it to peso inside the if-statements when we print to terminal and txt 
        pesos = centavos / 100.0;

        // Check for first case (less than 40hrs)
        if (hours <= 40) {
            payInPhp = (pesos * rate1) * hours;
            totalPay += payInPhp;

            // Print the results to the txt file
            fprintf(ofp, "|%11d |%8d |%11.2f |\n", centavos, hours, payInPhp);

        }
        // Check for second case (41-60hrs)
        else if (hours >= 41 && hours <= 60) {   
            payInPhp += pesos * 40;

            payInPhp += (pesos * rate2) * (hours - 40);

            totalPay += payInPhp;

            // Print the results to the txt file
            fprintf(ofp, "|%11d |%8d |%11.2f |\n", centavos, hours, payInPhp);

        }
        // Check for third case (more than 60hrs)
        else if (hours > 60) {
            payInPhp += pesos * 40;

            payInPhp += (pesos * rate2) * 20;

            payInPhp += (pesos * rate3) * (hours - 60);

            totalPay += payInPhp;

            // Print the results to the txt file
            fprintf(ofp, "|%11d |%8d |%11.2f |\n", centavos, hours, payInPhp);
        }

        // Print the results to the terminal
        printf("Pay at %d centavos/hr for %d hours is %.2f pesos\n\n", centavos, hours, payInPhp);
        
        // Reset total pay in peso per input
        payInPhp = 0;
    }
    
    // Close file pointer
    fclose(ofp);
    return 0;
}