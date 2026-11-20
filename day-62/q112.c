#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int curr = arr[0];
    int best = arr[0];

    for (int i = 1; i < n; i++) {
        // Extend the previous subarray or start fresh at arr[i]
        curr = (arr[i] > curr + arr[i]) ? arr[i] : curr + arr[i];

        if (curr > best)
            best = curr;
    }

    printf("%d\n", best);

    free(arr);
    return 0;
}