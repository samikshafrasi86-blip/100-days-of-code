#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open sample.txt\n");
        return 1;
    }

    int ch, last = 0;
    long chars = 0, words = 0, lines = 0;
    int inWord = 0;

    while ((ch = fgetc(fp)) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }

        last = ch;
    }

    // Last line without a trailing newline still counts as a line
    if (chars > 0 && last != '\n')
        lines++;

    fclose(fp);

    printf("Characters: %ld\n", chars);
    printf("Words: %ld\n", words);
    printf("Lines: %ld\n", lines);
    return 0;
}