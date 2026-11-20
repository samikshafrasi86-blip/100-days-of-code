#include <stdio.h>

int main() {
    int n;
    char name[50];
    int roll, marks;

    printf("Enter number of students: ");
    scanf("%d", &n);

    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: could not create students.txt\n");
        return 1;
    }

    // Phase 1: take input and write records to the file
    for (int i = 1; i <= n; i++) {
        printf("Student %d - Enter name, roll number, marks: ", i);
        scanf("%49s %d %d", name, &roll, &marks);
        fprintf(fp, "%s %d %d\n", name, roll, marks);
    }
    fclose(fp);

    // Phase 2: read records back and display them
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open students.txt\n");
        return 1;
    }

    printf("\n");
    while (fscanf(fp, "%49s %d %d", name, &roll, &marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
    }
    fclose(fp);

    return 0;
}
