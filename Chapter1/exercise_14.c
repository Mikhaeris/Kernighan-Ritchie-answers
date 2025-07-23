#include <stdio.h>
#define SQUARE "\xE2\x96\xA0"

int main()
{
    int c;
    int characters[95] = {0};
    int max_count;
    int i, j;

    max_count = 0;
    while ((c = getchar()) != EOF)
    {
        if (32 <= c && c <= 126)
        {
            ++characters[c-32];
            max_count =
                (characters[c-32] > max_count)
                ? characters[c-32] : max_count;
        }
    }

    for (i = 0; i < 95; ++i)
    {
        if (characters[i])
        {
            printf("%c: ", i+32);
            for (j = 0; j < characters[i]; ++j)
            {
                printf("%s ", SQUARE);
            }
            printf(":%i\n", characters[i]);
        }
    }

    return 0;
}
