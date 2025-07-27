#include <stdio.h>

#define MAX_LINE 1000
#define MAX_STR 10

int getline_c(char line[], int max_line);
void print_line(char line[], int length);
void print_half(char line[], int length, int max_str);

int main()
{
    int length;
    char line[MAX_LINE];

    while ((length = getline_c(line, MAX_LINE)) > 0)
    {
        if (length < MAX_STR)
        {
            print_line(line, length);
        }
        else
        {
            print_half(line, length, MAX_STR);
        }
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

void print_line(char line[], int length)
{
    int i;

    for (i = 0; i < length; ++i)
    {
        putchar(line[i]);
    }

    putchar('\n');
}

void print_half(char line[], int length, int max_str)
{
    int i, j;
    
    for (i = 0; i < length;)
    {
        for (j = i; j < length && j < max_str + i; ++j)
        {
            putchar(line[j]);
        }
        putchar('\n');
        i = j;
    }
}
