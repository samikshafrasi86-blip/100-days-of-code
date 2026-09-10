#include <stdio.h>

int main() {
    long long n;
    int digit, i;
    int count[10] = {0};
    int maxCount = 0, mostFrequent = 0;

    scanf("%lld", &n);

    // Count frequency of each digit
    while (n != 0) {
        digit = n % 10;
        count[digit]++;
        n = n / 10;
    }

    // Find the digit with maximum frequency
    for (i = 0; i <= 9; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequent = i;
        }
    }

    printf("%d", mostFrequent);

    return 0;
}