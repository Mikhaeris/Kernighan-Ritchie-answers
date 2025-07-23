#include <stdio.h>

#define MAX_LINE 1000

int getline_c(char line[], int max_line);
void reverse(char s[], int length);
void print_line(char s[], int length);

int main()
{
    int length;
    char line[MAX_LINE];

    while((length = getline_c(line, MAX_LINE)) > 0)
    {
        reverse(line, length);
        print_line(line, length);
    }

    return 0;
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
    
    line[i] = '\0';

    return i;
}

void reverse(char s[], int length)
{
    int l, r;

    l = 0, r = length-1;
    while (l < r)
    {
        char ch = s[l];
        s[l] = s[r];
        s[r] = ch;

        ++l;
        --r;
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
