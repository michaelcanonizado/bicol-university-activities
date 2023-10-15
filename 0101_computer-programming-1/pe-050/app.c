// Michael Xavier Canonizado | BSCS-1A
// This program asks the user to input 5 values corresponding to the grades of quizzes, midterms, finals, project, and recitation.  And computes the actual total grade.
#include <stdio.h>
#include <math.h>

int main() {
    //
    // DECLARE VARIABLES AND OPEN OUTPUT FILE
    //
    // Declare weights as const for readability, maintainability, and error avoidance. As these values are used throughout and in multiple parts of the program.
    const int WEIGHT_QUIZZES = 25;
    const int  WEIGHT_MIDTERMS = 20;
    const int  WEIGHT_FINALS = 25;
    const int WEIGHT_PORJECT = 20;
    const int  WEIGHT_RECITATION = 10;
    // Declare nessessary variables for inputted grades and totals
    float gradeQuizzes, gradeMidterms, gradeFinals, gradeProject, gradeRecitation;
    float AG, TG;
    // Open file
    FILE *ofp;
    ofp = fopen("grade.txt", "wt");


    //
    // GET GRADE INPUTS FROM USER
    //
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


    //
    // CALCULATIONS
    //
    // Calculate Actual Grade
    AG = ((gradeQuizzes * WEIGHT_QUIZZES) + (gradeMidterms * WEIGHT_MIDTERMS) + (gradeFinals * WEIGHT_FINALS) + (gradeProject * WEIGHT_PORJECT) + (gradeRecitation * WEIGHT_RECITATION)) / 100.0;
    // Calculate Transmuted Grade
    if (AG < 60) {
        TG = 60 + (AG / 4);
    } else {
        TG = 75 + ((AG - 60)/ 1.6);
    }
    // Floor/Round down Transmuted Grade to nearest integer
    TG = floor(TG);


    //
    // OUTPUT RESULTS
    //
    // Output to screen/terminal
    printf("\n--------------------------------------");
    printf("\n%-20s %-10s %s", "REQUIREMENT", "GRADE", "WEIGHT");
    printf("\n--------------------------------------");
    printf("\n%-20s %-10.2f %d%%", "Quizzes", gradeQuizzes, WEIGHT_QUIZZES);
    printf("\n%-20s %-10.2f %d%%", "Midterm Exam", gradeMidterms, WEIGHT_MIDTERMS);
    printf("\n%-20s %-10.2f %d%%", "Final Exam", gradeFinals, WEIGHT_FINALS);
    printf("\n%-20s %-10.2f %d%%", "Project", gradeProject, WEIGHT_PORJECT);
    printf("\n%-20s %-10.2f %d%%", "Recitation", gradeRecitation, WEIGHT_RECITATION);

    printf("\n\n%-20s %-10.2f", "Actual Grade:", AG);
    printf("\n%-20s %-10.0f", "Transmuted Grade:", TG);

    // Output to txt file
    fprintf(ofp, "\n--------------------------------------");
    fprintf(ofp, "\n%-20s %-10s %s", "REQUIREMENT", "GRADE", "WEIGHT");
    fprintf(ofp, "\n--------------------------------------");
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Quizzes", gradeQuizzes, WEIGHT_QUIZZES);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Midterm Exam", gradeMidterms, WEIGHT_MIDTERMS);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Final Exam", gradeFinals, WEIGHT_FINALS);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Project", gradeProject, WEIGHT_PORJECT);
    fprintf(ofp, "\n%-20s %-10.2f %d%%", "Recitation", gradeRecitation, WEIGHT_RECITATION);

    fprintf(ofp, "\n\n%-20s %-10.2f", "Actual Grade:", AG);
    fprintf(ofp, "\n%-20s %-10.0f", "Transmuted Grade:", TG);

    // Conditionally check Transmuted Grade to determine Grade Point and Description. Then output to screen/terminal and text file
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
    
    //
    // CLOSE FILE
    //
    fclose(ofp);

    return 0;
}