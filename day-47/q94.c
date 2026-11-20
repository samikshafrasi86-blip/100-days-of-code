#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char longest[1000] = "";
    char current[1000];
    int maxLen = 0, len = 0;

    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; ; i++) {
        char c = sentence[i];

        if (c != ' ' && c != '\n' && c != '\0') {
            current[len++] = c;
        } else {
            if (len > maxLen) {
                maxLen = len;
                current[len] = '\0';
                strcpy(longest, current);
            }
            len = 0;
            if (c == '\0') break;
        }
    }

    printf("%s\n", longest);
    return 0;
}