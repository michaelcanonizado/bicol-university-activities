#include <stdio.h>

int main(void) {
    int num = 18;
    double doublePoint = 3.14156234124523131;
    long double longDoublePoint = 724.141889;
    float floatingPoint = 9.12318;
    char name[] = "Michael Xavier";

    printf("\n'Integer: %.1d'", num);
    printf("\n'hexa: %x'", num);
    printf("\n'Float: %f'", floatingPoint);
    printf("\n'Float: %e'", floatingPoint);
    printf("\n'Double: %lf'", doublePoint);
    printf("\n'Long Double: %lf'", longDoublePoint);
    printf("\n'String: %20s'", name);

    return 0;
}