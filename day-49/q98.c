#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[1000];

    fgets(name, sizeof(name), stdin);

    // Remove trailing newline and trailing spaces
    int n = strcspn(name, "\n");
    while (n > 0 && name[n - 1] == ' ')
        n--;
    name[n] = '\0';

    // Find where the surname starts (just after the last space)
    int surnameStart = n;
    while (surnameStart > 0 && name[surnameStart - 1] != ' ')
        surnameStart--;

    // Print initials of all words before the surname
    int newWord = 1;
    for (int i = 0; i < surnameStart; i++) {
        if (name[i] == ' ') {
            newWord = 1;
        } else if (newWord) {
            printf("%c.", toupper((unsigned char)name[i]));
            newWord = 0;
        }
    }

    // Print the surname in full
    if (surnameStart > 0)
        printf(" ");
    printf("%s\n", name + surnameStart);

    return 0;
}