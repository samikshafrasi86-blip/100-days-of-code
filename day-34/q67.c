#include <stdio.h>

int main() {
    int n, pos, element;

    scanf("%d", &n);

    int arr[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &pos, &element);

    // Shift elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element at given position
    arr[pos] = element;
    n++;

    // Print updated array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }

    return 0;
}