#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_OF_STUDENTS 100


typedef struct {
    char name[MAX_NAME_LENGTH];
    int idNumber;
    int age;
    char gender;
} Student;

void groupStudents(Student allStudentsArray[MAX_NUM_OF_STUDENTS], int studentsCount, Student maleStudentsArray[MAX_NUM_OF_STUDENTS], int *maleStudentsCount, Student femaleStudentsArray[MAX_NUM_OF_STUDENTS], int *femaleStudentsCount) {

    int m = 0, f = 0;

    for (int i = 0; i < studentsCount; i++) {
        if (allStudentsArray[i].gender == 'M' || allStudentsArray[i].gender == 'm') {
            maleStudentsArray[m++] = allStudentsArray[i];
        } else if (allStudentsArray[i].gender == 'F' || allStudentsArray[i].gender == 'f') {
            femaleStudentsArray[f++] = allStudentsArray[i];
        }
    }

    *maleStudentsCount = m;
    *femaleStudentsCount = f;
}

void sortStudents(Student studentsArray[MAX_NUM_OF_STUDENTS], int studentsCount) {
    int isNotSortedFlag = 0;
    Student temp;

    for (int i = 0; i < (studentsCount - 1); i++) {
        for (int j = 0; j < (studentsCount - 1); j++) {
            if (strcmp(studentsArray[j].name, studentsArray[j+1].name) > 0) {
                temp = studentsArray[j];
                studentsArray[j] = studentsArray[j + 1];
                studentsArray[j + 1] = temp;
                isNotSortedFlag++;
            }
        }

        if (isNotSortedFlag == 0) {
            break;
        }
        isNotSortedFlag = 0;
    }
}

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("\nPlease specify the input file and output file names when executing the program...\n\n");
        return 1;
    }

    FILE *pInputFile = NULL;
    FILE *pOutputFile = NULL;    
    pInputFile = fopen(argv[1], "r");
    pOutputFile = fopen(argv[2], "w");


    int allStudentsCount = 0, maleStudentsCount = 0, femaleStudentsCount = 0, arrayIndex = 0;
    Student allStudentsArray[MAX_NUM_OF_STUDENTS];
    Student maleStudentsArray[MAX_NUM_OF_STUDENTS];
    Student femaleStudentsArray[MAX_NUM_OF_STUDENTS];

    fscanf(pInputFile, "%d", &allStudentsCount);

    while(1) {
        Student student;

        if (fscanf(pInputFile, "%s %d %d %c", student.name, &student.idNumber, &student.age, &student.gender) == EOF) {
            break;
        }

        allStudentsArray[arrayIndex] = student;
        arrayIndex++;
    }

    sortStudents(allStudentsArray, allStudentsCount);

    groupStudents(allStudentsArray, allStudentsCount, maleStudentsArray, &maleStudentsCount, femaleStudentsArray, &femaleStudentsCount);

    printf("\nMALE STUDENTS:\n");
    for (int i = 0; i < maleStudentsCount; i++) {
        printf("name: %10s | id: %5d | age: %4d | gender %3c\n", maleStudentsArray[i].name, maleStudentsArray[i].idNumber, maleStudentsArray[i].age, maleStudentsArray[i].gender);
    }
    printf("\n\nFEMALE STUDENTS:\n");
    for (int i = 0; i < femaleStudentsCount; i++) {
        printf("name: %10s | id: %5d | age: %4d | gender %3c\n", femaleStudentsArray[i].name, femaleStudentsArray[i].idNumber, femaleStudentsArray[i].age, femaleStudentsArray[i].gender);
    }

    printf("\n\n COUNT: %d\n", allStudentsCount);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}