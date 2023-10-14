#include <stdio.h>

int main() {
    // Declare Variables
    const float weightQuizzes = 0.25;
    const float  weightMidterms = 0.20;
    const float  weightFinals = 0.25;
    const float weightProject = 0.20;
    const float  weightRecitation = 0.1;

    float gradeQuizzes, gradeMidterms, gradeFinals, gradeProject, gradeRecitation;
    float AG, TG;

    // Get grades from user
    printf("\nEnter grade for Quizzes: ");
    scanf("%f", &gradeQuizzes);

    printf("Enter grade for Midterm exam: ");
    scanf("%f", &gradeMidterms);

    printf("Enter grade for Final exam: ");
    scanf("%f", &gradeFinals);

    printf("Enter grade for Project: ");
    scanf("%f", &gradeProject);

    printf("Enter grade for Recitation: ");
    scanf("%f", &gradeRecitation);

    // Calculate
    AG = (gradeQuizzes * weightQuizzes) + (gradeMidterms * weightMidterms) + (gradeFinals * weightFinals) + (gradeProject * weightProject) + (gradeRecitation * weightRecitation);

    if (AG < 60) {
        TG = 60 + (AG / 4);
    } else {
        TG = 75 + ((AG - 60)/ 1.6);
    }

    printf("\nActual Grade: %.2f", AG);
    printf("\nTransmuted Grade: %.0f", TG);



    // Output
    
    return 0;
}