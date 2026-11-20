#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];

    printf("Enter string: ");
    scanf("%100000s", s);

    int n = strlen(s);
    int last[256];
    for (int i = 0; i < 256; i++)
        last[i] = -1;

    int start = 0, best = 0;

    for (int i = 0; i < n; i++) {
        unsigned char c = (unsigned char)s[i];

        // Character already inside the current window: shrink from the left
        if (last[c] >= start)
            start = last[c] + 1;

        last[c] = i;

        if (i - start + 1 > best)
            best = i - start + 1;
    }

    printf("%d\n", best);
    return 0;
}