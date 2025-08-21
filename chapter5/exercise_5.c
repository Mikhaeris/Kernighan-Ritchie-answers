#include <stdio.h>

void test_my_func(char *s, char *t, void (*func)(char *, char *, unsigned long));

void my_strncpy(char *s, char *t, unsigned long n);
void my_strncat(char *s, char *t, unsigned long n);
int my_strncmp(char *s, char *t, unsigned long n);

int main () {
    char s[50] = "its letter";
    char t[20] = "not";

    printf("\nstrncpy:");
    test_my_func(s, t, my_strncpy);

    printf("\nstrncat:");
    test_my_func(s, t, my_strncat);

    printf("\nstrncpy:");
    printf("Strings:\n\tS: %s\n\tT: %s\n", s, t);
    int n = 3;
    printf("Difference in first %d elements: %d", n, my_strncmp(s, t, n));

    return 0;
}

/* TESTS */
void test_my_func(char *s, char *t, void (*func)(char *, char *, unsigned long)) {
    int n = 2;

    printf("\nBefore:\n\tS: %s\n\tT: %s", s, t);

    func(s, t, n);

    printf("\nAfter n=%d:\n\tS: %s\n\tT: %s\n", n, s, t);
}

/* FUNCTIONS */
void my_strncpy(char *s, char *t, unsigned long n) {
    for (unsigned long i = 0; i < n; ++i) {
        if (*t != '\0') {
            *s++ = *t++;
        } else {
            *s++ = *t;
        }
    }
}

void my_strncat(char *s, char *t, unsigned long n) {
    while (*s) {
        ++s;
    }

    for (unsigned long i = 0; i < n; ++i) {
        *s++ = *t++;
    }

    *s = '\0';
}

int my_strncmp(char *s, char *t, unsigned long n) {
    for (unsigned long i = 0; i < n; ++i) {
        if (*s != *t) {
            return *s - *t;
        }
        ++s, ++t;
    }

    return 0;
}
