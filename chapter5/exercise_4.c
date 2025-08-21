#include <stdio.h>

int my_strend(char *s, char *t);

int main() {
    char s[] = "some letter, i think";
    char t[] = "i think";

    printf("S: %s\nT: %s", s, t);
    printf("T in end of S: %d", my_strend(s,t));

    return 0;
}

int my_strend(char *s, char *t) {
    while (*s) {
        ++s;
    }
    
    int length_t = 0;
    while (*t) {
        ++t;
        ++length_t;
    }

    for (int i = 0; i < length_t; ++i) {
        if (*s-- != *t--) {
            return 0;
        }
    }

    return 1;
}
