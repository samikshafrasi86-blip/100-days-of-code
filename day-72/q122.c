#include <stdio.h>

int main() {
    char line[256];

    FILE *fp = fopen("info.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open info.txt\n");
        return 1;
    }

    // fgets returns NULL at EOF
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}