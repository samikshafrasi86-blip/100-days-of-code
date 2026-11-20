#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Lomuto partition: pivot is the last element of arr[low..high]
int partition(int arr[], int low, int high) {
    // Use a middle pivot (moved to the end) to avoid worst case on sorted input
    int mid = low + (high - low) / 2;
    swap(&arr[mid], &arr[high]);

    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int target) {
    while (low <= high) {
        int p = partition(arr, low, high);
        if (p == target)
            return arr[p];
        else if (p > target)
            high = p - 1;
        else
            low = p + 1;
    }
    return -1; // not reached for valid k
}

int main() {
    int n, k;

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

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid k\n");
        free(arr);
        return 1;
    }

    printf("%d\n", quickSelect(arr, 0, n - 1, k - 1));

    free(arr);
    return 0;
}