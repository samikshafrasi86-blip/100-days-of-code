#include <stdio.h>

int main() {
    int num, temp, digit;
    int sum = 0, fact, i;

    scanf("%d", &num);

    temp = num;

    while (temp > 0) {
        digit = temp % 10;

        fact = 1;
        for (i = 1; i <= digit; i++) {
            fact *= i;
        }

        sum += fact;
        temp /= 10;
    }

    if (sum == num)
        printf("Strong number\n");
    else
        printf("Not strong number\n");

    return 0;
}