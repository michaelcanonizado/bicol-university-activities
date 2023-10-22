#include <stdio.h>

int main() {
    char userCharInput;

    printf("ALPHABET SONG\n");
    printf("Enter a userCharInput: ");
    scanf("%c", &userCharInput);

    // Guard clause to check if input is invalid (not an uppercase). If invlaid, immediately throw an error and exit program.
    if ((userCharInput < 'A' || userCharInput > 'Z') && (userCharInput < 'a' || userCharInput > 'z')) {
        printf("\n\t\'%c\' - Invalid Character", userCharInput);
        return 1;
    }
    
    // Check if input is a lowercase alphabet. If true, turn input to upper case by manipulating the ASCII value.
    if (userCharInput >= 'a' && userCharInput <= 'z') {
        userCharInput = userCharInput - 32;
        printf("\nINPUT: %c", userCharInput);
        printf("\nLOWERCASE\n\n");
        return 0;
    }

    

    return 0;
}