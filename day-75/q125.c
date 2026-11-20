#include <stdio.h>
#include <string.h>

int main() {
    char text[500];

    FILE *fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error: could not open data.txt\n");
        return 1;
    }

    printf("Enter text to append: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';   // remove trailing newline

    // Newline first, so the text starts on a fresh line
    fprintf(fp, "\n%s", text);

    fclose(fp);

    printf("File updated successfully with appended text.\n");
    return 0;
}