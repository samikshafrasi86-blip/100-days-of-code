#include <stdio.h>
#include <math.h>

int pivotInteger(int n) {
    int total = n * (n + 1) / 2;
    int x = (int) sqrt((double) total);

    if (x * x == total) {
        return x;
    }
    return -1;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("%d\n", pivotInteger(n));
    return 0;
}