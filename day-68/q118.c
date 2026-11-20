#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);

    long long actual = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        actual += nums[i];
    }

    long long expected = (long long)n * (n + 1) / 2;

    printf("%lld\n", expected - actual);

    free(nums);
    return 0;
}