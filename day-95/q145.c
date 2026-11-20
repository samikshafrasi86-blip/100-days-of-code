#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

struct Student findTopper(struct Student s[], int n) {
    struct Student top = s[0];

    for (int i = 1; i < n; i++) {
        if (s[i].marks > top.marks) {
            top = s[i];
        }
    }

    return top;
}

int main() {
    struct Student s[100], topper;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", s[i].name, &s[i].roll_no, &s[i].marks);
    }

    topper = findTopper(s, n);

    printf("Top Student: %s | Roll: %d | Marks: %d",
           topper.name, topper.roll_no, topper.marks);

    return 0;
}