#include <stdio.h>

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("\nPlease specify the input file and output file names when executing the program...\n\n");
        return 1;
    }

    FILE *pInputFile = NULL;
    FILE *pOutputFile = NULL;    
    pInputFile = fopen(argv[1], "r");
    pOutputFile = fopen(argv[2], "w");

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}