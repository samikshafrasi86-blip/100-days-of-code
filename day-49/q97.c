#include <stdio.h>
#include <ctype.h>

int main() {
    char name[1000];

    fgets(name, sizeof(name), stdin);

    int newWord = 1;  // 1 means the next letter starts a word

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ' || name[i] == '\n') {
            newWord = 1;
        } else if (newWord) {
            printf("%c.", toupper((unsigned char)name[i]));
            newWord = 0;
        }
    }

    printf("\n");
    return 0;
}
