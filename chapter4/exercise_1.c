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
    while (getline_c(line, MAX_LINE) > 0)
    {
        position = strindex(line, pattern);
        if (position >= 0)
        {
            printf("%sLast position: %d\n", line, position);
            ++found;
        }
    }

    return found;
}

int getline_c(char s[], int lim)
{
    int c, i;

    i = 0;
    while (0 < --lim && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

/* modified for last entry */
int strindex(char s[], char t[])
{
    int i, j, k;
    int ans;

    ans = -1;
    for (i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k);

        if (k > 0 && t[k] == '\0')
        {
            ans = i;
        }
    }

    return ans;
}
