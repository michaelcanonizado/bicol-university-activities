// Name: CANONIZADO, MICHAEL XAVIER ,E
// Block: BSCS-1A
// Title; Programming Exercise 3
// Description: A program that calculates the ratings and average of 5 quizes of a student

#include <stdio.h>

int main() {
    // Initialized a name variable with 40 bytes
    char name[40];
    // Initialized score variables
    int q1score, q2score, q3score, q4score, q5score;
    // Initialized total variables
    int q1total, q2total, q3total, q4total, q5total;
    // Initialized rating variables
    float q1rating, q2rating, q3rating, q4rating, q5rating;
    // Initialized average variable
    float average;

    // Ask user for name
    printf("\nInput name of student: ");
    scanf("%s", name);

    // Prompt user for the instructions
    printf("\nPlease input five pairs of integer values representing the total number of points and score of Juan's quizzes. ");
    
    // Ask user for the quiz scores, with the format: <total> <score>
    printf("\nInput Quiz 1 : ");
    scanf("%d %d", &q1total, &q1score);
    printf("Input Quiz 2 : ");
    scanf("%d %d", &q2total, &q2score);
    printf("Input Quiz 3 : ");
    scanf("%d %d", &q3total, &q3score);
    printf("Input Quiz 4 : ");
    scanf("%d %d", &q4total, &q4score);    
    printf("Input Quiz 5 : ");
    scanf("%d %d", &q5total, &q5score);

    // Calculate the ratings for each quiz
    q1rating = ((float)q1score / q1total) * 100;
    q2rating = ((float)q2score / q2total) * 100;
    q3rating = ((float)q3score / q3total) * 100;
    q4rating = ((float)q4score / q4total) * 100;
    q5rating = ((float)q5score / q5total) * 100;

    // Calculate average rating for all 5 quizes
    average = (q1rating + q2rating + q3rating + q4rating + q5rating) / 5.0;

    // Print out the results properly formatted as a table
    printf("\n----------------------------------");
    printf("\n|%6s |%6s |%6s |%6s  |", "Quiz#", "SCORE", "TOTAL", "RATE");
    printf("\n----------------------------------");
    
    printf("\n|%-6d |%6d |%6d |%6.2f%% |", 1, q1score, q1total, q1rating);
    printf("\n|%-6d |%6d |%6d |%6.2f%% |", 2, q2score, q2total, q2rating);
    printf("\n|%-6d |%6d |%6d |%6.2f%% |", 3, q3score, q3total, q3rating);
    printf("\n|%-6d |%6d |%6d |%6.2f%% |", 4, q4score, q4total, q4rating);
    printf("\n|%-6d |%6d |%6d |%6.2f%% |", 5, q5score, q5total, q5rating);

    printf("\n\nQuiz Average: %.2f%%", average);

    return 0;
}