#include <stdio.h>
#include <string.h>

int main() {
    char s1[1000], s2[1000];
    char doubled[2000];

    scanf("%s", s1);
    scanf("%s", s2);

    // Rotations must have the same length
    if (strlen(s1) != strlen(s2)) {
        printf("Not rotation\n");
        return 0;
    }

    // Build s1 + s1
    strcpy(doubled, s1);
    strcat(doubled, s1);

    // If s2 is inside s1s1, it is a rotation of s1
    if (strstr(doubled, s2) != NULL)
        printf("Rotation\n");
    else
        printf("Not rotation\n");

    return 0;
}