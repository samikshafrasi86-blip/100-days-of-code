#include <stdio.h>

int main() {
    int num, digit;
    int product = 1;

    scanf("%d", &num);

    while (num > 0) {
        digit = num % 10;

        if (digit % 2 != 0) {
            product *= digit;
        }

        num /= 10;
    }

    printf("%d\n", product);

    return 0;
}