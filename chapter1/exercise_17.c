#include <stdio.h>

#define MAX_LINE 1000
#define MIN_LENGTH 80

int getline_c(char line[], int max_line);
void print_line(char line[], int length);

int main()
{
    int length;
    char line[MAX_LINE];
    
    while ((length = getline_c(line, MAX_LINE)) > 0)
    {
        if (length > MIN_LENGTH)
        {
            print_line(line, length);
        }
    }

    return 0;
}

int getline_c(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

void print_line(char line[], int length)
{
    int i;

    for (i = 0; i < length; ++i)
    {
        putchar(line[i]);
    }
    putchar('\n');
}
