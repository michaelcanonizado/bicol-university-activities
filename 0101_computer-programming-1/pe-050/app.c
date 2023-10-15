#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    // Declare Variables
    const int weightQuizzes = 25;
    const int  weightMidterms = 20;
    const int  weightFinals = 25;
    const int weightProject = 20;
    const int  weightRecitation = 10;

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
    AG = ((gradeQuizzes * weightQuizzes) + (gradeMidterms * weightMidterms) + (gradeFinals * weightFinals) + (gradeProject * weightProject) + (gradeRecitation * weightRecitation)) / 100.0;

    if (AG < 60) {
        TG = 60 + (AG / 4);
    } else {
        TG = 75 + ((AG - 60)/ 1.6);
    }

    TG = floor(TG);


    // Output
    printf("\n--------------------------------------");
    printf("\n%-20s %-10s %s", "REQUIREMENT", "GRADE", "WEIGHT");
    printf("\n--------------------------------------");
    printf("\n%-20s %-10.2f %d%%", "Quizzes", gradeQuizzes, weightQuizzes);
    printf("\n%-20s %-10.2f %d%%", "Midterm Exam", gradeMidterms, weightMidterms);
    printf("\n%-20s %-10.2f %d%%", "Final Exam", gradeFinals, weightFinals);
    printf("\n%-20s %-10.2f %d%%", "Project", gradeProject, weightProject);
    printf("\n%-20s %-10.2f %d%%", "Recitation", gradeRecitation, weightRecitation);

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

    printf("\n\n%-20s %-10.2f", "Actual Grade:", AG);
    printf("\n%-20s %-10.0f", "Transmuted Grade:", TG);

    printf("\n%-20s %-10.2f", "Grade Point:", GP);
    printf("\n%-20s %-10s", "Description:", description);
    
    return 0;
}