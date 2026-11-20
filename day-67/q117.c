#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    printf("Enter size of first array: ");
    scanf("%d", &m);
    int *nums1 = (int *)malloc(m * sizeof(int));
    printf("Enter %d elements: ", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &nums1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n);
    int *nums2 = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums2[i]);

    int *merged = (int *)malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Pick the smaller front element from either array
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    // Copy leftovers
    while (i < m)
        merged[k++] = nums1[i++];
    while (j < n)
        merged[k++] = nums2[j++];

    for (int x = 0; x < m + n; x++)
        printf("%d ", merged[x]);
    printf("\n");

    free(nums1);
    free(nums2);
    free(merged);
    return 0;
}