#include <stdio.h>

int main() {
    char srcName[100], destName[100];
    int ch;

    printf("Enter source file name: ");
    scanf("%99s", srcName);
    printf("Enter destination file name: ");
    scanf("%99s", destName);

    FILE *src = fopen(srcName, "r");
    if (src == NULL) {
        printf("Error: could not open source file %s\n", srcName);
        return 1;
    }

    FILE *dest = fopen(destName, "w");
    if (dest == NULL) {
        printf("Error: could not create destination file %s\n", destName);
        fclose(src);
        return 1;
    }

    // Copy character by character until EOF
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully to %s\n", destName);
    return 0;
}