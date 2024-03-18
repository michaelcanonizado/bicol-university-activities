#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_OF_STUDENTS 100

// Define student struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    int idNumber;
    int age;
    char gender;
} Student;

void groupStudents(Student allStudentsArray[MAX_NUM_OF_STUDENTS], int studentsCount, Student maleStudentsArray[MAX_NUM_OF_STUDENTS], int *maleStudentsCount, Student femaleStudentsArray[MAX_NUM_OF_STUDENTS], int *femaleStudentsCount) {

    int m = 0, f = 0;

    // Iterate through the allStudentsArray. If male add them to maleStudentsArray; if female, add them to femaleStudentsArray.
    for (int i = 0; i < studentsCount; i++) {
        if (allStudentsArray[i].gender == 'M' || allStudentsArray[i].gender == 'm') {
            maleStudentsArray[m++] = allStudentsArray[i];
        } else if (allStudentsArray[i].gender == 'F' || allStudentsArray[i].gender == 'f') {
            femaleStudentsArray[f++] = allStudentsArray[i];
        }
    }

    // Dereference male and female counters and give them the count fo the found male and female
    *maleStudentsCount = m;
    *femaleStudentsCount = f;
}

void sortStudents(Student studentsArray[MAX_NUM_OF_STUDENTS], int studentsCount) {
    int isNotSortedFlag = 0;
    Student temp;

    // Use bubble sort to sort the students alphabetically
    for (int i = 0; i < (studentsCount - 1); i++) {
        for (int j = 0; j < (studentsCount - 1); j++) {
            if (strcmp(studentsArray[j].name, studentsArray[j+1].name) > 0) {
                temp = studentsArray[j];
                studentsArray[j] = studentsArray[j + 1];
                studentsArray[j + 1] = temp;
                isNotSortedFlag++;
            }
        }

        // If array is already sorted, exit out
        if (isNotSortedFlag == 0) {
            break;
        }
        isNotSortedFlag = 0;
    }
}

int main(int argc, char *argv[]) {
    
    // Check if user has executed the program along with the input and output paths
    if (argc < 3) {
        printf("\nPlease specify the input file and output file names when executing the program...\n\n");
        return 1;
    }

    // Open file pointers using what user inputted
    FILE *pInputFile = NULL;
    FILE *pOutputFile = NULL;    
    pInputFile = fopen(argv[1], "r");
    pOutputFile = fopen(argv[2], "w");

    // Declar variables 
    int allStudentsCount = 0, maleStudentsCount = 0, femaleStudentsCount = 0, arrayIndex = 0;
    Student allStudentsArray[MAX_NUM_OF_STUDENTS];
    Student maleStudentsArray[MAX_NUM_OF_STUDENTS];
    Student femaleStudentsArray[MAX_NUM_OF_STUDENTS];

    // Scan the first line of the input file which contains the total number of students in the file
    fscanf(pInputFile, "%d", &allStudentsCount);

    // Iterate through the whole file until EOF, reading each student, storing them in a struct, and pushing it into allStudentsArray
    while(1) {
        Student student;

        if (fscanf(pInputFile, "%s %d %d %c", student.name, &student.idNumber, &student.age, &student.gender) == EOF) {
            break;
        }

        allStudentsArray[arrayIndex] = student;
        arrayIndex++;
    }

    // Sort allStudentsArray
    sortStudents(allStudentsArray, allStudentsCount);
    // Group the students into male and female
    groupStudents(allStudentsArray, allStudentsCount, maleStudentsArray, &maleStudentsCount, femaleStudentsArray, &femaleStudentsCount);

    // Print results to terminal/screen
    printf("\n%-15s %5s %5s", "NAME", "ID#", "AGE");
    printf("\n---------------------------");

    printf("\nMALE:\n");
    for (int i = 0; i < maleStudentsCount; i++) {
        printf("%-15s %5.2d %5.2d\n", maleStudentsArray[i].name, maleStudentsArray[i].idNumber, maleStudentsArray[i].age);
    }
    printf("\nFEMALE:\n");
    for (int i = 0; i < femaleStudentsCount; i++) {
        printf("%-15s %5.2d %5.2d\n", femaleStudentsArray[i].name, femaleStudentsArray[i].idNumber, femaleStudentsArray[i].age);
    }

    // Print results to output file
    fprintf(pOutputFile, "\n%-15s %5s %5s", "NAME", "ID#", "AGE");
    fprintf(pOutputFile, "\n---------------------------");

    fprintf(pOutputFile, "\nMALE:\n");
    for (int i = 0; i < maleStudentsCount; i++) {
        fprintf(pOutputFile, "%-15s %5.2d %5.2d\n", maleStudentsArray[i].name, maleStudentsArray[i].idNumber, maleStudentsArray[i].age);
    }
    fprintf(pOutputFile, "\nFEMALE:\n");
    for (int i = 0; i < femaleStudentsCount; i++) {
        fprintf(pOutputFile, "%-15s %5.2d %5.2d\n", femaleStudentsArray[i].name, femaleStudentsArray[i].idNumber, femaleStudentsArray[i].age);
    }

    // Close file pointers
    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}