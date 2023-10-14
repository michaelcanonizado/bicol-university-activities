#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    // Declare Variables
    const float weightQuizzes = 0.25;
    const float  weightMidterms = 0.20;
    const float  weightFinals = 0.25;
    const float weightProject = 0.20;
    const float  weightRecitation = 0.1;

    float gradeQuizzes, gradeMidterms, gradeFinals, gradeProject, gradeRecitation;
    float AG, TG, GP;
    char description[25];

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

    AG = floor(AG);

    if (AG < 60) {
        TG = 60 + (AG / 4);
    } else {
        TG = 75 + ((AG - 60)/ 1.6);
    }

    if (TG >= 95 && TG <= 100) {
        GP = 1.00;
        strcpy(description, "Outstanding");
    } else if (TG >= 91 && TG <= 94) {
        GP = 1.25;
        strcpy(description, "Superior");
    }else if (TG >= 88 && TG <= 90) {
        GP = 1.50;
        strcpy(description,"Very Satisfactory");
    }else if (TG >= 86 && TG <= 87) {
        GP = 1.75;
        strcpy(description,"Very Satisfactory");
    }else if (TG >= 84 && TG <= 85) {
        GP = 2.00;
        strcpy(description,"Satisfactory");
    }else if (TG >= 82 && TG <= 83) {
        GP = 2.25;
        strcpy(description,"Satisfactory");
    }else if (TG >= 79 && TG <= 81) {
        GP = 2.50;
        strcpy(description,"Fair");
    }else if (TG >= 77 && TG <= 78) {
        GP = 2.75;
        strcpy(description,"Fair");
    }else if (TG >= 75 && TG <= 76) {
        GP = 3.00;
        strcpy(description,"Fair");
    }else if (TG >= 60 && TG <= 74) {
        GP = 5.00;
        strcpy(description,"Failure");
    }



    // Output
    printf("\n-------------------------------------------");
    printf("\n%-20s %10s %10s", "REQUIREMENT", "GRADE", "WEIGHT");
    printf("\n-------------------------------------------");
    printf("\n%-20s %10.2f %-10.0f%%", "Quizzes", gradeQuizzes, weightQuizzes * 100);
    printf("\n%-20s %10.2f %-10.0f%%", "Midterm Exam", gradeMidterms, weightMidterms * 100);
    printf("\n%-20s %10.2f %-10.0f%%", "Final Exam", gradeFinals, weightFinals * 100);
    printf("\n%-20s %10.2f %-10.0f%%", "Project", gradeProject, weightProject * 100);
    printf("\n%-20s %10.2f %-10.0f%%", "Recitation", gradeRecitation, weightRecitation * 100);

    printf("\n\nActual Grade: %.2f", AG);
    printf("\nTransmuted Grade: %.0f", TG);
    printf("\nGrade Point: %.2f", GP);
    printf("\nDescription: %s", description);
    
    return 0;
}