#include <stdio.h>
#include <string.h>

enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main() {
    const char *names[] = {
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
        "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
    };
    char input[10];
    int found = -1;

    printf("Enter month (JAN to DEC): ");
    scanf("%9s", input);

    for (int m = JAN; m <= DEC; m++) {
        if (strcmp(input, names[m]) == 0) {
            found = m;
            break;
        }
    }

    if (found == -1) {
        printf("Invalid month\n");
        return 1;
    }

    enum Month month = (enum Month)found;

    switch (month) {
        case FEB:
            printf("28 or 29 days\n");
            break;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            printf("30 days\n");
            break;
        default:
            printf("31 days\n");
    }

    return 0;
}