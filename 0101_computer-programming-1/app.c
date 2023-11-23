#include <stdio.h>

int f(int a, int b) {

    printf("function running...\n");

    if (a == 0 || b == 0){
        return 0;
    } else if (a == b) {
        return f(a-1,b-1) + 2*a-1;
    } else if (a > b) {
        return f(a-b,b) + f(b,b);
    } else if (a < b) {
        return f(a,a) + f(b-a,a);
    }
}

int main (void) {
    printf("RESULT: %d",f(3,2));;
    return 0;
}
