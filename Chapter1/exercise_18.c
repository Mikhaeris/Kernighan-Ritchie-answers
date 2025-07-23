#include <stdio.h>

#define MAX_LINE 1000

int getline_c(char line[], int max_line);
int delete_tail(char line[], int length);
void print_line(char line[], int length);

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

int delete_tail(char line[], int length)
{
    int i;

    for(i = length; i > 0; --i)
    {
        if (line[i] == ' ' || line[i] == '\t' ||
            line[i] == '\n' || line[i] == '\b' ||
            line[i] == '\0')
        {
            line[i] = 0;
        }
        else
        {
            line[i+1] = '\0';
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
