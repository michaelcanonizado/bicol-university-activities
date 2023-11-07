#include <stdio.h>

int main(void) {
    const float rate1 = 1.0;
    const float rate2 = 1.5;
    const float rate3 = 2.0;

    float centavos, pesos, hour, payInPhp, totalPay;

    while(1) {
        printf("Please input a pair of integers (ctrl-D to end): ");
        if (scanf("%f %f", &centavos, &hour) == EOF) {
            break;
        }

        pesos = centavos / 100;

        if (hour <= 40) {
            payInPhp = (pesos * rate1) * hour;
            totalPay += payInPhp;
        } else if (hour >= 41 && hour <= 60) {
            hour -= 40;
            
            payInPhp += pesos * 40;

            payInPhp += (pesos * rate2) * hour;

            totalPay += payInPhp;

        } else if (hour > 60) {
            hour -= 60;

            payInPhp += pesos * 40;

            payInPhp += (pesos * rate2) * 20;

            payInPhp += (pesos * rate3) * hour;

            totalPay += payInPhp;
        }

        printf("Pay at %.0f centavos/hr for %.0f hours is %.2f pesos\n\n", centavos, hour, payInPhp);
        
        payInPhp = 0;
    }

    // Print to txt here

    return 0;
}