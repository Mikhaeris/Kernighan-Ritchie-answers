#include <stdio.h>

#define MAX_LINE 1000

int getline_c(char line[], int max_line);
int delete_tail(char s[], int length);
void print_line(char s[], int length);

int main()
{
    int length;
    char line[MAX_LINE];

    while ((length = getline_c(line, MAX_LINE)) > 0)
    {
        length = delete_tail(line, length);
        print_line(line, length);
    }

    return 0;
}

int getline_c(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

int delete_tail(char s[], int length)
{
    int i;

    for(i = length; i > 0; --i)
    {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'||
            s[i] == '\b' || s[i] == '\0')
        {
            s[i] = 0;
        }
        else
        {
            s[i+1] = '\0';
            return i+1;
        }
    }

    return 0;
}

void print_line(char line[], int length)
{
    int i;

    for (i = 0; i < length; ++i)
    {
        putchar(line[i]);
    }
    putchar('\n');
}
