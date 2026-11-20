#include <stdio.h>

int main() {
    char s[1000];

    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Vowels=0, Consonants=0\n");
        return 0;
    }

    int vowels = 0, consonants = 0;

    for (int i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != '\r'; i++) {
        char ch = s[i];

        if (ch >= 'A' && ch <= 'Z')
            ch = ch + ('a' - 'A');          // convert to lowercase

        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("Vowels=%d, Consonants=%d\n", vowels, consonants);
    return 0;
}