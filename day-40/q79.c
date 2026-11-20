#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    int first = 1;

    for (int d = 0; d <= r + c - 2; d++) {
        int lo = (d - c + 1 > 0) ? d - c + 1 : 0;   // smallest valid row
        int hi = (d < r - 1) ? d : r - 1;           // largest valid row

        if (d % 2 == 1) {
            for (int i = lo; i <= hi; i++) {
                if (!first) printf(" ");
                printf("%d", a[i][d - i]);
                first = 0;
            }
        } else {
            for (int i = hi; i >= lo; i--) {
                if (!first) printf(" ");
                printf("%d", a[i][d - i]);
                first = 0;
            }
        }
    }
    printf("\n");

    return 0;
}