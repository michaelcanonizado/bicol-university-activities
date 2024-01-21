// Name: CANONIZADO, MICHAEL XAVIER ,E.
// Block: BSCS-1A
// Title; Programming Exercise 3
// Description: A program that calculates the ratings and average of 5 quizes of a student

#include <stdio.h>

int main() {
    // declare a name variable with a max of 40 characters
    char name[40];
    // declare quiz score variables as short int to lessen memory usage, and utilize what was learned in lesson 6
    short int q1score, q2score, q3score, q4score, q5score;
    // declare quiz total variables as short int to lessen memory usage, and utilize what was learned in lesson 6
    short int q1total, q2total, q3total, q4total, q5total;
    // declare quiz rating variables
    float q1rating, q2rating, q3rating, q4rating, q5rating;
    // declare average variable
    float averageRating;

    printf("Creating output file");
    FILE *outputFile;
    outputFile = fopen("app.txt", "wt");

    // Ask user for name of student
    printf("\nInput name of student: ");
    scanf("%s", name);

    // Prompt user for the instructions
    printf("\nPlease input five pairs of integer values representing the total number of points and score of %s's quizzes.", name);
    
    // Ask user for the quiz scores, with the format: <total> <score>
    printf("\nInput Quiz 1 : ");
    scanf("%hi %hi", &q1total, &q1score);
    printf("Input Quiz 2 : ");
    scanf("%hi %hi", &q2total, &q2score);
    printf("Input Quiz 3 : ");
    scanf("%hi %hi", &q3total, &q3score);
    printf("Input Quiz 4 : ");
    scanf("%hi %hi", &q4total, &q4score);    
    printf("Input Quiz 5 : ");
    scanf("%hi %hi", &q5total, &q5score);

    printf("\nVerifying inputs...");
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
        printf("\nInvalid inputs! Please rerun program and consider the following:\n- Quiz input format is: <total> <score>\n- Quiz total must be greater than 0\n- Quiz score must not be a negative number\n- Quiz score must not be greater than Quiz total");

        return 1;
    }

    printf("\nCalculating inputs...");

    // Calculate the ratings for each quiz
    q1rating = ((float)q1score / q1total) * 100;
    q2rating = ((float)q2score / q2total) * 100;
    q3rating = ((float)q3score / q3total) * 100;
    q4rating = ((float)q4score / q4total) * 100;
    q5rating = ((float)q5score / q5total) * 100;

    // Calculate average rating for all 5 quizes
    averageRating = (q1rating + q2rating + q3rating + q4rating + q5rating) / 5.0;

    
    printf("\nWriting to file...");

    // Print out the results properly formatted as a table
    fprintf(outputFile, "----------------------------------");
    fprintf(outputFile, "\n|%6s |%6s |%6s |%6s  |", "QUIZ#", "SCORE", "TOTAL", "RATE");
    fprintf(outputFile, "\n----------------------------------");
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 1, q1score, q1total, q1rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 2, q2score, q2total, q2rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 3, q3score, q3total, q3rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 4, q4score, q4total, q4rating);
    fprintf(outputFile, "\n|%-6d |%6hi |%6hi |%6.2f%% |", 5, q5score, q5total, q5rating);

    fprintf(outputFile, "\n\nQuiz Average: %.2f%%", averageRating);

    printf("\nDone writing to file...");

    printf("\nClosing file...");
    fclose(outputFile);
    printf("\nTask done...");


    return 0;
}