#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);

    int spaces = 0, digits = 0, special = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '\n')
            continue;
        if (c == ' ')
            spaces++;
        else if (isdigit((unsigned char)c))
            digits++;
        else if (!isalpha((unsigned char)c))
            special++;
    }

    printf("Spaces=%d, Digits=%d, Special=%d", spaces, digits, special);
    return 0;
}