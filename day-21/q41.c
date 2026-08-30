#include <stdio.h>

int main() {
    int num, temp, first, last, digits = 0;
    int firstPlace = 1, middle, result;

    scanf("%d", &num);

    temp = num;
    last = temp % 10;

    while (temp >= 10) {
        temp /= 10;
        digits++;
        firstPlace *= 10;
    }

    first = temp;
    middle = (num % firstPlace) / 10;

    result = last * firstPlace + middle * 10 + first;

    printf("%d\n", result);

    return 0;
}