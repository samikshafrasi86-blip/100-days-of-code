#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    scanf("%s", str);

    int left = 0, right = strlen(str) - 1;
    int isPalin = 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalin = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalin)
        printf("Palindrome");
    else
        printf("Not palindrome");

    return 0;
}