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

    // Open File
    FILE *ofp;
    ofp = fopen("grade.txt", "wt");

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

    printf("\n\n%-20s %-10.2f", "Actual Grade:", AG);
    printf("\n%-20s %-10.0f", "Transmuted Grade:", TG);


    fprintf(ofp, "\n--------------------------------------");
    fprintf(ofp, "\n%-20s %-10s %s", "REQUIREMENT", "GRADE", "WEIGHT");
    fprintf(ofp, "\n--------------------------------------");
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Quizzes", gradeQuizzes, weightQuizzes);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Midterm Exam", gradeMidterms, weightMidterms);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Final Exam", gradeFinals, weightFinals);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Project", gradeProject, weightProject);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Recitation", gradeRecitation, weightRecitation);

    fprintf(ofp, "\n\n%-20s %-10.2f", "Actual Grade:", AG);
    fprintf(ofp, "\n%-20s %-10.0f", "Transmuted Grade:", TG);


    if (TG >= 95 && TG <= 100) {
        printf("\n%-20s %-10.2f", "Grade Point:", 1.00);
        printf("\n%-20s %-10s", "Description:", "Outstanding");

        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 1.00);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Outstanding");
    } else if (TG >= 91 && TG <= 94) {
        printf("\n%-20s %-10.2f", "Grade Point:", 1.25);
        printf("\n%-20s %-10s", "Description:", "Superior");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 1.25);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Superior");
    }else if (TG >= 88 && TG <= 90) {
        printf("\n%-20s %-10.2f", "Grade Point:", 1.50);
        printf("\n%-20s %-10s", "Description:", "Very Satisfactory");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 1.50);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Very Satisfactory");
    }else if (TG >= 86 && TG <= 87) {
        printf("\n%-20s %-10.2f", "Grade Point:", 1.75);
        printf("\n%-20s %-10s", "Description:", "Very Satisfactory");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 1.75);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Very Satisfactory");
    }else if (TG >= 84 && TG <= 85) {
        printf("\n%-20s %-10.2f", "Grade Point:", 2.00);
        printf("\n%-20s %-10s", "Description:", "Satisfactory");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 2.00);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Satisfactory");
    }else if (TG >= 82 && TG <= 83) {
        printf("\n%-20s %-10.2f", "Grade Point:", 2.25);
        printf("\n%-20s %-10s", "Description:", "Satisfactory");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 2.25);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Satisfactory");
    }else if (TG >= 79 && TG <= 81) {
        printf("\n%-20s %-10.2f", "Grade Point:", 2.50);
        printf("\n%-20s %-10s", "Description:", "Fair");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 2.50);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Fair");
    }else if (TG >= 77 && TG <= 78) {
        printf("\n%-20s %-10.2f", "Grade Point:", 2.75);
        printf("\n%-20s %-10s", "Description:", "Fair");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 2.75);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Fair");
    }else if (TG >= 75 && TG <= 76) {
        printf("\n%-20s %-10.2f", "Grade Point:", 3.00);
        printf("\n%-20s %-10s", "Description:", "Fair");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 3.00);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Fair");
    }else if (TG >= 60 && TG <= 74) {
        printf("\n%-20s %-10.2f", "Grade Point:", 5.00);
        printf("\n%-20s %-10s", "Description:", "Failure");
        
        fprintf(ofp, "\n%-20s %-10.2f", "Grade Point:", 5.00);
        fprintf(ofp, "\n%-20s %-10s", "Description:", "Failure");
    }
    
    fclose(ofp);

    return 0;
}