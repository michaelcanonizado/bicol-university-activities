#include <stdio.h>

int main(void) {
    double value1, value2, total;
    char operation;

    printf("Please input an operation(+,-,*,/): ");
    scanf("%c", &operation);

    printf("\nPlease input 2 values separated by a space <val 1> <val 2>:");
    scanf("%lf %lf", &value1, &value2);

    switch(operation)
    {
        case '+':
            printf("\nAdd");
            total = value1 + value2;
            break;
        case '-':
            printf("\nSubtract");
            total = value1 - value2;
            break;
        case '*':
            printf("\nMultiply");
            total = value1 * value2;
            break;
        case '/':
            printf("\nDivide");
            total = value1 / value2;
            break;
        default:
            printf("\nOperation not found! Please rerun program again\n");
            return 1;
    }

    printf("\nTotal: %.4lf", total);

    printf("\nClosing calculator...");

    return 0;
}