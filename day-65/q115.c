#include <stdio.h>
#include <string.h>

int main() {
    char s[100005], t[100005];

    printf("Enter string s: ");
    scanf("%100000s", s);
    printf("Enter string t: ");
    scanf("%100000s", t);

    int n = strlen(s);
    int m = strlen(t);

    if (n != m) {
        printf("Not Anagram\n");
        return 0;
    }

    int count[26] = {0};

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            printf("Not Anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");
    return 0;
}