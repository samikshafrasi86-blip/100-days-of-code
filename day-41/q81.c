#include <stdio.h>

int main() {
    char s[1000];

    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("0\n");
        return 0;
    }

    int count = 0;
    while (s[count] != '\0' && s[count] != '\n' && s[count] != '\r')
        count++;

    printf("%d\n", count);
    return 0;
}
