#include <stdio.h>

#define MAX_LINE 1000
#define TAB_LENGTH 4

int getline_c(char line[], int max_line);
void entab(char line[], int length);
void print_line(char line[], int length);

int main()
{
    int length;
    char line[MAX_LINE];

    while ((length = getline_c(line, MAX_LINE)) > 0)
    {
        entab(line, length);
        print_line(line, length);
    }
}

int getline_c(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = c;

    return i;
}

void entab(char s[], int length)
{
    int l, r;
    int count;

    count = 0;
    l = r = 0;
    for (; s[r] != '\n'; ++r)
    {
        if (s[r] == ' ')
        {
            ++count;
        }

        if (count == TAB_LENGTH)
        {
            s[l] = '\t';
            ++l;
            count = 0;
        }
    }

    l += count;
    s[l++] = '\n';
    s[l++] = '\0';
    for (; s[l] != 0; ++l)
    {
        s[l] = 0;
    }
}

void print_line(char s[], int length)
{
    int i;

    for (i = 0; i < length; ++i)
    {
        putchar(s[i]);
    }
    putchar('\n');
}
