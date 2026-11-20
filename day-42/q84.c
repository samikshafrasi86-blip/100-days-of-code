#include <stdio.h>

int main() {
    char s[1000];

    if (fgets(s, sizeof(s), stdin) == NULL)
        return 0;

    for (int i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != '\r'; i++) {
        char ch = s[i];

        if (ch >= 'a' && ch <= 'z')
            ch = ch - ('a' - 'A');          // convert to uppercase

        printf("%c", ch);
    }
    printf("\n");

    return 0;
}