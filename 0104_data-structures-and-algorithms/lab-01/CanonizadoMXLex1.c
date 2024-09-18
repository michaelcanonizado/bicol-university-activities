#include <stdio.h>
#include <math.h>

int main(void) {
    float a,b,c;
    double discriminant,x1,x2;

    // Ask user for the Coefficients a,b, and c
    printf("Enter A: ");
    scanf("%f", &a);
    printf("Enter B: ");
    scanf("%f", &b);
    printf("Enter C: ");
    scanf("%f", &c);

    // Not a quadratic equation if a == 0
    if (a == 0) {
        printf("Invalid quadratic equation!");
        return 0;
    }

    // Calculat discriminant
    discriminant = (b*b)-(4*a*c);

    // If discriminant is greater than 0, there are 2 roots
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
    
        printf("Roots: x = %lf, x = %lf\n",x1,x2);
    } 
    // If discriminant == 0, there is one root
    else if (discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / 2*a;
        printf("Roots: x = %lf\n",x1);
    } 
    // If discriminant is less than 0, the roots are imaginary
    else if (discriminant < 0) {
        double realPart, imaginaryPart;

        realPart = -b / (2*a);
        imaginaryPart = (sqrt((-discriminant)) / (2*a));

       printf("Imaginary roots: x = %.2lf + %.2lfi, x = = %.2lf - %.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}