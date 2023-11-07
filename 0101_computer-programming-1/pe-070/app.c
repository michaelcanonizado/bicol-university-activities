#include <stdio.h>

int main(void) {
    float num1, num2;

    while(1) {
        printf("Please input a pair of integers (ctrl-D to end): ");
        if (scanf("%f %f", &num1, &num2) == EOF) {
            break;
        }

        printf("Pay at %f centavos/hr for %f hours is %f\n\n", num1, num2, num1 + num2);
    }

    return 0;
}