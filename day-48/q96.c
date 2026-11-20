#include <stdio.h>
#include <string.h>

// Reverse characters of str[start..end] in place
void reverse(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char sentence[1000];

    fgets(sentence, sizeof(sentence), stdin);

    // Remove trailing newline
    sentence[strcspn(sentence, "\n")] = '\0';

    int n = strlen(sentence);
    int start = 0;

    for (int i = 0; i <= n; i++) {
        // A word ends at a space or at the end of the string
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            reverse(sentence, start, i - 1);
            start = i + 1;
        }
    }

    printf("%s\n", sentence);
    return 0;
}