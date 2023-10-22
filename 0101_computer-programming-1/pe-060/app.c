#include <stdio.h>

int main() {
    char userCharInput;
    char verifiedChar;

    printf("ALPHABET SONG\n");
    printf("Enter a letter: ");
    scanf("%c", &userCharInput);

    // Guard clause to check if input is invalid (not an uppercase). If invlaid, immediately throw an error and exit program.
    if ((userCharInput < 'A' || userCharInput > 'Z') && (userCharInput < 'a' || userCharInput > 'z')) {
        printf("\t\'%c\' - Invalid character", userCharInput);
        return 1;
    }
    
    // Check if input is a lowercase alphabet. If true, turn input to upper case by manipulating the ASCII value.
    if (userCharInput >= 'a' && userCharInput <= 'z') {
        verifiedChar = userCharInput - 32;
    } else {
        verifiedChar = userCharInput;
    }

    // Switch through the char, then print the corresponding lyrics.
    switch (verifiedChar) {
        case 'A':
            printf("\n\'%c\' - You're adorable", userCharInput);
            break;
        case 'B':
            printf("\n\'%c\' - You're so beautiful", userCharInput);
            break;
        case 'C':
            printf("\n\'%c\' - You're a cutie full of charms", userCharInput);
            break;
        case 'D':
            printf("\n\'%c\' - You're a darling and", userCharInput);
            break;
        case 'E':
            printf("\n\'%c\' - You're exciting and", userCharInput);
            break;
        case 'F':
            printf("\n\'%c\' - You're a feather in my arms", userCharInput);
            break;
        case 'G':
            printf("\n\'%c\' - You look good to me", userCharInput);
            break;
        case 'H':
            printf("\n\'%c\' - You're so heavenly", userCharInput);
            break;
        case 'I':
            printf("\n\'%c\' - You're the one I idolize", userCharInput);
            break;
        case 'J':
            printf("\n\'%c\' - We're like Jack and Jill", userCharInput);
            break;
        case 'K':
            printf("\n\'%c\' - You're so kissable", userCharInput);
            break;
        case 'L':
            printf("\n\'%c\' - Is the love light in oyur eyes", userCharInput);
            break;
        case 'M':
        case 'N':
        case 'O':
        case 'P':
            printf("\n\'%c\' - I could do on all day", userCharInput);
            break;
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
            printf("\n\'%c\' - Alphabetically speaking you're okay", userCharInput);
            break;
        case 'U':
            printf("\n\'%c\' - Made my life complete", userCharInput);
            break;
        case 'V':
            printf("\n\'%c\' - Means you're very sweet", userCharInput);
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            printf("\n\'%c\' - It's fun to wander through", userCharInput);
            printf("\n      The alphabet with you");
            printf("\n      To tell you what you mean to me");
            break;
    }

    return 0;
}