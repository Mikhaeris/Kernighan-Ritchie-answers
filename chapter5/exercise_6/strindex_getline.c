#include <stdio.h>

#define MAX_LINE 1000

int getline_c(char line[], int max);

int strindex(char soure[], char searchfor[]);

int main()
{
    char pattern[] = "ould";
    char line[MAX_LINE];
    int found, position;

    found = 0;
    while (getline_c(line, MAX_LINE) > 0) {
        position = strindex(line, pattern);
        if (position >= 0) {
            printf("%sLast position: %d\n", line, position);
            ++found;
        }
    }

    return found;
}

int getline_c(char *s, int lim)
{
    char *st = s;
    while (0 < --lim && (*st = getchar()) != EOF && *st++ != '\n')
        ;

    *st = '\0';
    return st-s;
}

/* modified for last entry */
int strindex(char *s, char *t)
{
    int ans = -1;
    for (char *se = s; *se != '\0'; ++se) {
        char *k = t;
        for (char *j = se; *k != '\0' && *j == *k; ++j, ++k)
            ;

        if (k != t && *k == '\0') {
            ans = se-s;
        }
    }

    return ans;
}
