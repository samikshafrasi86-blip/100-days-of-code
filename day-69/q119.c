#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000000

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    char *seen = (char *)calloc(MAXV + 1, sizeof(char));

    // Single pass: first value already marked is the repeated one
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (x < 0 || x > MAXV)
            continue;

        if (seen[x]) {
            printf("%d\n", x);
            free(nums);
            free(seen);
            return 0;
        }
        seen[x] = 1;
    }

    printf("No repeated element\n");

    free(nums);
    free(seen);
    return 0;
}