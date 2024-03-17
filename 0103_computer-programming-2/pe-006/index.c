#include <stdio.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_OF_STUDENTS 100

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("\nPlease specify the input file and output file names when executing the program...\n\n");
        return 1;
    }

    FILE *pInputFile = NULL;
    FILE *pOutputFile = NULL;    
    pInputFile = fopen(argv[1], "r");
    pOutputFile = fopen(argv[2], "w");

    typedef struct {
        char name[MAX_NAME_LENGTH];
        int id;
        int age;
        char gender;
    } Student;

    int studentsCount = 0, arrayIndex = 0;
    Student studentsArray[MAX_NUM_OF_STUDENTS];

    fscanf(pInputFile, "%d", &studentsCount);

    while(1) {
        Student student;

        if (fscanf(pInputFile, "%s %d %d %c", student.name, &student.id, &student.age, &student.gender) == EOF) {
            break;
        }

        studentsArray[arrayIndex] = student;
        arrayIndex++;
    }

    for (int i = 0; i < studentsCount; i++) {
        printf("name: %10s | id: %5d | age: %4d | gender %3c\n", studentsArray[i].name, studentsArray[i].id, studentsArray[i].age, studentsArray[i].gender);
    }

    printf("\n\n COUNT: %d\n", studentsCount);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}