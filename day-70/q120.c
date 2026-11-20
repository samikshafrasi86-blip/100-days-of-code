#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1005];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline
    str[strcspn(str, "\n")] = '\0';

    int newWord = 1;   // 1 when the next character starts a word

    for (int i = 0; str[i] != '\0'; i++) {
        if (newWord)
            str[i] = toupper((unsigned char)str[i]);
        else
            str[i] = tolower((unsigned char)str[i]);

        newWord = (str[i] == ' ');
    }

    printf("%s\n", str);
    return 0;
}