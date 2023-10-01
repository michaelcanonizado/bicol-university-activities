// Name: CANONIZADO, MICHAEL XAVIER ,E.
// Block: BSCS-1A
// Title; Programming Exercise 3
// Description: A program that calculates the ratings and average of 5 quizes of a student from an input file and outputs it in an output file.

#include <stdio.h>

int main() {
    // declare a name variable with a max of 40 characters
    char name[50];
    // declare quiz score variables as short int to lessen memory usage, and utilize what was learned in lesson 6
    short int q1score, q2score, q3score, q4score, q5score;
    // declare quiz total variables as short int to lessen memory usage, and utilize what was learned in lesson 6
    short int q1total, q2total, q3total, q4total, q5total;
    // declare quiz rating variables
    float q1rating, q2rating, q3rating, q4rating, q5rating;
    // declare average variable
    float averageRating;

    // Use a string constant as paths for input and output instead of hardcoding. For ease of access and usability in prompts: e.g. printf("Reading %s...", inputFileName); or printf("Outputting results to %s", outputFileName);
    const char inputFileName[] = "input.txt";
    const char outputFileName[] = "output.txt";

    FILE *inputFile;
    FILE *outputFile;
    inputFile = fopen(inputFileName, "rt");
    outputFile = fopen(outputFileName, "wt");

    if (inputFile == NULL) {
        printf("%s not found...", inputFileName);
        return 1;
    }

    fscanf(inputFile, "%s", name);
    fscanf(inputFile, "%hi %hi", &q1total, &q1score);
    fscanf(inputFile, "%hi %hi", &q2total, &q2score);
    fscanf(inputFile, "%hi %hi", &q3total, &q3score);
    fscanf(inputFile, "%hi %hi", &q4total, &q4score);
    fscanf(inputFile, "%hi %hi", &q5total, &q5score);

    // Close input file as soon as scanning is done for best practice (Resource Managment, Error Handling, Predictability, etc.).
    fclose(inputFile);


    // Use a guard clause to check if user inputs are valid
    if(
        // Quiz total should be greater than 0
        (q1total <= 0 || 
        q2total <= 0 || 
        q3total <= 0 || 
        q4total <= 0 || 
        q5total <= 0)
        || 
        // Quiz score should not be a negative number
        (q1score < 0 || 
        q2score < 0 || 
        q3score < 0 || 
        q4score < 0 || 
        q5score < 0)
        ||
        // Quiz score cannot be greater its total
        (q1score > q1total || 
        q2score > q2total || 
        q3score > q3total || 
        q4score > q4total || 
        q5score > q5total)
    ) {
        printf("\nInvalid inputs! Please rerun program. Check your input file and consider the following:\n- First line must be the name of the student\n- One quiz input per line\n- Quiz input format is: <total> <score>\n- Quiz total must be greater than 0\n- Quiz score must not be a negative number\n- Quiz score must not be greater than quiz total\n\n");

        return 1;
    }

    // Calculate the ratings for each quiz
    q1rating = ((float)q1score / q1total) * 100;
    q2rating = ((float)q2score / q2total) * 100;
    q3rating = ((float)q3score / q3total) * 100;
    q4rating = ((float)q4score / q4total) * 100;
    q5rating = ((float)q5score / q5total) * 100;

    // Calculate average rating for all 5 quizes
    averageRating = (q1rating + q2rating + q3rating + q4rating + q5rating) / 5.0;


    //
    // OUTPUTING IN RESULTS AND AVERAGE IN A TXT FILE
    //
    // OUPUT name and the results properly formatted as a table as output.txt
    fprintf(outputFile, "Name of student: %s", name);
    fprintf(outputFile, "\n----------------------------------");
    fprintf(outputFile, "\n %6s |%6s |%6s |%6s  |", "QUIZ#", "SCORE", "TOTAL", "RATE");
    fprintf(outputFile, "\n----------------------------------");
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 1, q1score, q1total, q1rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 2, q2score, q2total, q2rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 3, q3score, q3total, q3rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 4, q4score, q4total, q4rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 5, q5score, q5total, q5rating);
    fprintf(outputFile, "\n\nRATE AVERAGE: %.2f%%", averageRating);

    
    fclose(outputFile);



    //
    // PRINTING results and average in the terminal
    //
    // PRINT name and the results properly formatted as a table in the terminal
    printf("Name of student: %s", name);
    printf("\n----------------------------------");
    printf("\n %6s |%6s |%6s |%6s  |", "QUIZ#", "SCORE", "TOTAL", "RATE");
    printf("\n----------------------------------");
    printf("\n|%-6d |%6hi |%6hi |%6.2f%% |", 1, q1score, q1total, q1rating);
    printf("\n|%-6d |%6hi |%6hi |%6.2f%% |", 2, q2score, q2total, q2rating);
    printf("\n|%-6d |%6hi |%6hi |%6.2f%% |", 3, q3score, q3total, q3rating);
    printf("\n|%-6d |%6hi |%6hi |%6.2f%% |", 4, q4score, q4total, q4rating);
    printf("\n|%-6d |%6hi |%6hi |%6.2f%% |", 5, q5score, q5total, q5rating);
    printf("\n\nRATE AVERAGE: %.2f%%", averageRating);

    return 0;
}