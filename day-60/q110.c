#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid k\n");
        free(arr);
        return 1;
    }

    // Deque implemented as an array of indices
    int *dq = (int *)malloc(n * sizeof(int));
    int front = 0, rear = -1;   // empty when front > rear

    for (int i = 0; i < n; i++) {
        // Remove indices that are out of the current window
        if (front <= rear && dq[front] <= i - k)
            front++;

        // Remove smaller elements from the back
        while (front <= rear && arr[dq[rear]] <= arr[i])
            rear--;

        dq[++rear] = i;

        // Window is complete: print its maximum
        if (i >= k - 1)
            printf("%d ", arr[dq[front]]);
    }
    printf("\n");

    free(arr);
    free(dq);
    return 0;
}