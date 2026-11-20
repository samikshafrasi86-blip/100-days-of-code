#include <stdio.h>

int main() {
    char s[1000];

    if (fgets(s, sizeof(s), stdin) == NULL)
        return 0;

    int n = 0;
    while (s[n] != '\0' && s[n] != '\n' && s[n] != '\r')
        n++;

    for (int i = n - 1; i >= 0; i--)
        printf("%c", s[i]);
    printf("\n");

    return 0;
}