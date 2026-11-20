#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000000

int main() {
    int n, target;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    // seen[v] = index of value v, or -1 if not seen
    int *seen = (int *)malloc((MAXV + 1) * sizeof(int));
    for (int v = 0; v <= MAXV; v++)
        seen[v] = -1;

    for (int i = 0; i < n; i++) {
        int need = target - nums[i];

        if (need >= 0 && need <= MAXV && seen[need] != -1) {
            printf("%d %d\n", seen[need], i);
            free(nums);
            free(seen);
            return 0;
        }

        if (nums[i] >= 0 && nums[i] <= MAXV)
            seen[nums[i]] = i;
    }

    printf("-1 -1\n");

    free(nums);
    free(seen);
    return 0;
}