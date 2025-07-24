#include <stdio.h>

#define TAB_LENGTH 4

void detab(int *column);

int main()
{
    int ch, column;

    column = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\t')
        {
            detab(&column);
        }
        else
        {
            putchar(ch);
            if (ch == '\n')
            {
                column = 0;
            }
            else
            {
                ++column;
            }
        }
    }

    return 0;
}

void detab(int *column)
{
    int i, spaces;

    spaces = TAB_LENGTH - (*column % TAB_LENGTH);
    for (i = 0; i < spaces; ++i)
    {
        putchar(' ');
        ++*column;
    }
}
