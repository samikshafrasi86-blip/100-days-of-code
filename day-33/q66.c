#include <stdio.h>

int main() {
    int n, element, pos;

    scanf("%d", &n);

    int arr[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &element);

    // Find the correct position
    pos = n;

    for (int i = 0; i < n; i++) {
        if (element < arr[i]) {
            pos = i;
            break;
        }
    }

    // Shift elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element
    arr[pos] = element;
    n++;

    // Print the updated array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        if (i < n - 1)
            printf(" ");
    }

    return 0;
}