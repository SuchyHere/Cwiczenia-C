#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT_COUNT 100

typedef struct {
    float grade;
    char name[50];
} Student;

void sort(Student *s, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (s[j].grade < s[j + 1].grade) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student students[STUDENT_COUNT];
    srand(time(NULL));

    for (int i = 0; i < STUDENT_COUNT; i++) {
        students[i].grade = (float)rand() / (float)(RAND_MAX) * 3.0f + 2.0f; //ocena od 2.0 do 5.0
        sprintf(students[i].name, "Student_%d", i + 1);
    }

    int size = sizeof(students) / sizeof(students[0]);
    sort(students, size);

    for (int i = 0; i < size; i++) {
        printf("Student: %s, Ocena: %.2f\n", students[i].name, students[i].grade);
    }

    return 0;
}
