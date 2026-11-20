#include <stdio.h>

int main() {
    char str[1000];
    char ch;

    scanf("%s", str);
    scanf(" %c", &ch);

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            count++;
    }

    printf("%d", count);
    return 0;
}