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

    // Queue of indices of negative numbers
    int *q = (int *)malloc(n * sizeof(int));
    int front = 0, rear = -1;   // empty when front > rear

    for (int i = 0; i < n; i++) {
        // Add current index if negative
        if (arr[i] < 0)
            q[++rear] = i;

        // Window is complete
        if (i >= k - 1) {
            // Remove indices that are outside the window
            while (front <= rear && q[front] < i - k + 1)
                front++;

            if (front <= rear)
                printf("%d ", arr[q[front]]);
            else
                printf("0 ");
        }
    }
    printf("\n");

    free(arr);
    free(q);
    return 0;
}