#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int age;

    FILE *fp = fopen("info.txt", "w");
    if (fp == NULL) {
        printf("Error: could not create file.\n");
        return 1;
    }

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';   // remove trailing newline

    printf("Enter age: ");
    scanf("%d", &age);

    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Age: %d\n", age);

    fclose(fp);

    printf("File created successfully! Data written to info.txt\n");
    return 0;
}