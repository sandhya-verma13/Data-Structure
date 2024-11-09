#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    int age;
};
struct Student* findStudentById(struct Student* students, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            return &students[i]; 
        }
    }
    return NULL; 
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
    }
    int searchId;
    printf("Enter the student ID to search: ");
    scanf("%d", &searchId);
    struct Student* foundStudent = findStudentById(students, n, searchId);
    if (foundStudent != NULL) {
        printf("Student Found:\n");
        printf("ID: %d, Name: %s, Age: %d\n", foundStudent->id, foundStudent->name, foundStudent->age);
    } else {
        printf("Student with ID %d not found.\n", searchId);
    }
    free(students);
    return 0;
}

