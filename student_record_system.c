#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int   roll;
    char  name[50];
    char  course[30];
    float marks;
};

struct Student s[MAX];
int count = 0;

int findIndex(int roll) {
    for (int i = 0; i < count; i++)
        if (s[i].roll == roll) return i;
    return -1;
}

void addStudent(void) {
    if (count >= MAX) { printf("Record list is full!\n"); return; }
    struct Student t;
    printf("Enter roll number: ");
    scanf("%d", &t.roll);
    if (findIndex(t.roll) != -1) { printf("Roll number already exists!\n"); return; }
    printf("Enter name: ");
    scanf(" %49[^\n]", t.name);
    printf("Enter course: ");
    scanf(" %29[^\n]", t.course);
    printf("Enter marks: ");
    scanf("%f", &t.marks);
    s[count++] = t;
    printf("Record added successfully.\n");
}

void printRow(struct Student st) {
    printf("%-8d %-20s %-15s %-6.2f\n", st.roll, st.name, st.course, st.marks);
}

void displayAll(void) {
    if (count == 0) { printf("No records found.\n"); return; }
    printf("\n%-8s %-20s %-15s %-6s\n", "Roll", "Name", "Course", "Marks");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) printRow(s[i]);
}

void searchStudent(void) {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    int i = findIndex(roll);
    if (i == -1) { printf("Student not found.\n"); return; }
    printf("\n%-8s %-20s %-15s %-6s\n", "Roll", "Name", "Course", "Marks");
    printRow(s[i]);
}

void updateStudent(void) {
    int roll;
    printf("Enter roll number to update: ");
    scanf("%d", &roll);
    int i = findIndex(roll);
    if (i == -1) { printf("Student not found.\n"); return; }
    printf("Enter new name: ");
    scanf(" %49[^\n]", s[i].name);
    printf("Enter new course: ");
    scanf(" %29[^\n]", s[i].course);
    printf("Enter new marks: ");
    scanf("%f", &s[i].marks);
    printf("Record updated successfully.\n");
}

void deleteStudent(void) {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    int i = findIndex(roll);
    if (i == -1) { printf("Student not found.\n"); return; }
    for (int j = i; j < count - 1; j++) s[j] = s[j + 1];
    count--;
    printf("Record deleted successfully.\n");
}

int main(void) {
    int choice;
    do {
        printf("\n===== STUDENT RECORD MANAGEMENT =====\n");
        printf("1. Add Student\n2. Display All\n3. Search Student\n");
        printf("4. Update Student\n5. Delete Student\n6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); choice = 0; }
        switch (choice) {
            case 1: addStudent();    break;
            case 2: displayAll();    break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Thank you!\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);
    return 0;
}
