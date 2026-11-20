#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[1000], s2[1000];
    int count[256] = {0};

    scanf("%s", s1);
    scanf("%s", s2);

    // Different lengths can never be anagrams
    if (strlen(s1) != strlen(s2)) {
        printf("Not anagrams\n");
        return 0;
    }

    // Increment for s1, decrement for s2
    for (int i = 0; s1[i] != '\0'; i++) {
        count[(unsigned char)tolower(s1[i])]++;
        count[(unsigned char)tolower(s2[i])]--;
    }

    // If all counts return to zero, the strings are anagrams
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("Not anagrams\n");
            return 0;
        }
    }

    printf("Anagrams\n");
    return 0;
}