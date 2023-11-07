#include <stdio.h>

int main(void) {
    const float rate1 = 1.0;
    const float rate2 = 1.5;
    const float rate3 = 2.0;

    float centavos, pesos, hours, payInPhp, totalPay;

    FILE *ofp;
    ofp = fopen("payment.txt", "wt");

    fprintf(ofp, "Computation of your payment for this week\n");
    fprintf(ofp, "-------------------------------------\n");
    fprintf(ofp, "|%s| %s | %s |\n", "Rate(cts/hr)", "# Hours", "Pay(Pesos)");
    fprintf(ofp, "-------------------------------------\n");

    while(1) {
        printf("Please input a pair of integers (ctrl-D to end): ");
        if (scanf("%f %f", &centavos, &hours) == EOF) {
            printf("This is the end of your input.\n\n");

            printf("TOTAL PAY: %.2f pesos", totalPay);
            fprintf(ofp, "\nTOTAL PAY: PhP %.2f", totalPay);
            break;
        }

        pesos = centavos / 100;

        if (hours <= 40) {
            payInPhp = (pesos * rate1) * hours;
            totalPay += payInPhp;

            fprintf(ofp, "|%11.0f |%8.0f |%11.2f |\n", centavos, hours, payInPhp);

        } else if (hours >= 41 && hours <= 60) {   
            payInPhp += pesos * 40;

            payInPhp += (pesos * rate2) * (hours - 40);

            totalPay += payInPhp;

            fprintf(ofp, "|%11.0f |%8.0f |%11.2f |\n", centavos, hours, payInPhp);

        } else if (hours > 60) {
            payInPhp += pesos * 40;

            payInPhp += (pesos * rate2) * 20;

            payInPhp += (pesos * rate3) * (hours - 60);

            totalPay += payInPhp;

            fprintf(ofp, "|%11.0f |%8.0f |%11.2f |\n", centavos, hours, payInPhp);
        }

        printf("Pay at %.0f centavos/hr for %.0f hours is %.2f pesos\n\n", centavos, hours, payInPhp);
        
        payInPhp = 0;
    }

    // Print to txt here
    fclose(ofp);
    return 0;
}