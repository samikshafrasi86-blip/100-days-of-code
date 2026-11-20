#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n], answer[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Pass 1: answer[i] = product of all elements to the left of i
    answer[0] = 1;
    for (int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Pass 2: multiply by product of all elements to the right of i
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(",");
        printf("%d", answer[i]);
    }
    printf("]\n");

    return 0;
}