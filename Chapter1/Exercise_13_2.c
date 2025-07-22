#include <stdio.h>

#define SQUARE "\xE2\x96\xA0"
#define MAXLEN 20

int main()
{
    int c;
    int word_length;
    int max_freq;
    int i, j;
    int counts[MAXLEN] = {0};

    word_length = max_freq = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            ++word_length; 
        }
        else if (word_length != 0)
        {
            if (word_length <= MAXLEN)
            {
                ++counts[word_length-1];
                if (counts[word_length-1] > max_freq)
                {
                    max_freq = counts[word_length-1];
                }
            }
            word_length = 0;
        }
    }

    /* last word*/
    if (word_length > 0 && word_length <= MAXLEN)
    {
        ++counts[word_length-1];
        if (counts[word_length-1] > max_freq)
        {
            max_freq = counts[word_length-1];
        }
    }

    for (i = max_freq; i > 0; --i)
    {
        printf("%-2i", i);
        for (j = 0; j < MAXLEN; ++j)
        {
            if (counts[j] >= i)
            {
                printf("%5s", SQUARE);
            }
            else
            {
                printf("%2c ", ' ');
            }
        }
        putchar('\n');
    }
    
    printf("  ");
    for (i = 0; i < MAXLEN; ++i)
    {
        printf("%3i", i+1);
    }
    putchar('\n');

    return 0;
}
