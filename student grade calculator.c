#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float marks[MAX_SUBJECTS];
    float total;
    float average;
    char grade;
} Student;

char get_grade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

int main() {
    Student students[MAX_STUDENTS];
    int n_students, n_subjects;
    printf("Enter number of students: ");
    scanf("%d", &n_students);
    printf("Enter number of subjects: ");
    scanf("%d", &n_subjects);

    for (int i = 0; i < n_students; i++) {
        printf("Student %d name: ", i+1);
        scanf("%s", students[i].name);
        students[i].total = 0;
        for (int j = 0; j < n_subjects; j++) {
            printf("Enter marks for Subject %d: ", j+1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }
        students[i].average = students[i].total / n_subjects;
        students[i].grade = get_grade(students[i].average);
    }

    printf("\n--- Results ---\n");
    for (int i = 0; i < n_students; i++) {
        printf("%s: Total = %.2f, Average = %.2f, Grade = %c\n",
               students[i].name,
               students[i].total,
               students[i].average,
               students[i].grade);
    }
    return 0;
}
