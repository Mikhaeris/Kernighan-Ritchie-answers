#include <stdio.h>

int main()
{
    int i, lim, c;
    char s[10];

    lim = 10;
    for (i = 0; i < lim-1; ++i)
    {
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        if (c == EOF)
        {
            break;
        }

        s[i] = c;
    }

    return 0;
}
