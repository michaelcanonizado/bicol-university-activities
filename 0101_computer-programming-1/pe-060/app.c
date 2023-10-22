// Michael Xavier Canonizado | BSCS-1A
// This program asks the user to input a letter (lowercase/uppercase) and will output the corresponding lyric to the inputted letter, via a switch case.
#include <stdio.h>

int main() {
    //
    // DECLARE VARIABLES
    //
    char userCharInput;
    char verifiedChar;


    //
    // GET INPUT FROM USER
    //
    printf("ALPHABET SONG\n");
    printf("Enter a letter: ");
    scanf("%c", &userCharInput);


    //
    // VERIFY USER INPUT
    //
    // Guard clause to check if input is invalid (not a letter). If invlaid, immediately throw an error and exit program.
    if ((userCharInput < 'A' || userCharInput > 'Z') && (userCharInput < 'a' || userCharInput > 'z')) {
        printf("\t\'%c\' - Invalid character", userCharInput);
        return 1;
    }
    // Check if letter is lowercase. If true, turn letter to uppercase by manipulating the ASCII value, then assign it to another variable that is going to be switched through.
    if (userCharInput >= 'a' && userCharInput <= 'z') {
        verifiedChar = userCharInput - 32;
    } else {
        verifiedChar = userCharInput;
    }
    // Another variable is need as this variable will contain the verified and transformed letter. But the original input is still needed, as it is going to be the one used to printed out with the lyrics. E.g. 
    //"'y' - It's fun to wander through", and not 
    //"'Y' - It's fun to wander through".
    // Another and much sleeker apporach would be to use the 'toupper()' function to convert the letter into a single case. But that requires the <ctype.h> library.


    //
    // OUTPUT THE CORRESPONDING LYRIC
    //
    switch (verifiedChar) {
        case 'A':
            printf("\t\'%c\' - You're adorable", userCharInput);
            break;
        case 'B':
            printf("\t\'%c\' - You're so beautiful", userCharInput);
            break;
        case 'C':
            printf("\t\'%c\' - You're a cutie full of charms", userCharInput);
            break;
        case 'D':
            printf("\t\'%c\' - You're a darling and", userCharInput);
            break;
        case 'E':
            printf("\t\'%c\' - You're exciting and", userCharInput);
            break;
        case 'F':
            printf("\t\'%c\' - You're a feather in my arms", userCharInput);
            break;
        case 'G':
            printf("\t\'%c\' - You look good to me", userCharInput);
            break;
        case 'H':
            printf("\t\'%c\' - You're so heavenly", userCharInput);
            break;
        case 'I':
            printf("\t\'%c\' - You're the one I idolize", userCharInput);
            break;
        case 'J':
            printf("\t\'%c\' - We're like Jack and Jill", userCharInput);
            break;
        case 'K':
            printf("\t\'%c\' - You're so kissable", userCharInput);
            break;
        case 'L':
            printf("\t\'%c\' - Is the love light in oyur eyes", userCharInput);
            break;
        case 'M':
        case 'N':
        case 'O':
        case 'P':
            printf("\t\'%c\' - I could do on all day", userCharInput);
            break;
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
            printf("\t\'%c\' - Alphabetically speaking you're okay", userCharInput);
            break;
        case 'U':
            printf("\t\'%c\' - Made my life complete", userCharInput);
            break;
        case 'V':
            printf("\t\'%c\' - Means you're very sweet", userCharInput);
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            printf("\t\'%c\' - It's fun to wander through", userCharInput);
            printf("\n\t      The alphabet with you");
            printf("\n\t      To tell you what you mean to me");
            break;
    }

    return 0;
}