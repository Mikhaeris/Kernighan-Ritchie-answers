#include <stdio.h>

void my_strcat(char *s, char *t);

int main() {
    char s[20] = "I love ice cream";
    char t[4] = ",no";

    printf("Before: %s\n", s);
    my_strcat(s, t);
    printf("After: %s\n", s);

    return 0;
}

void my_strcat(char *s, char *t) {
    while (*s) {
        ++s;
    }

    while (*s++ = *t++)
        ;
}
