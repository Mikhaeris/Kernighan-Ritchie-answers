#include <stdio.h>

#define SQUARE "\xE2\x96\xA0"
#define MAXLENGTH 20

int main()
{
    int c;
    int curr_length;
    int i, j;
    int counts[MAXLENGTH] = {0};

    curr_length = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            ++curr_length; 
        }
        else if (curr_length != 0)
        {
            if (curr_length <= MAXLENGTH)
            {
                ++counts[curr_length-1];
            }
            curr_length = 0;
        }
    }
    
    ++counts[curr_length-1];
    curr_length = 0;

    for (i = 0; i < MAXLENGTH; ++i)
    {
        printf("%-2i: ", i+1);
        for (j = 0; j < counts[i]; ++j)
        {
            printf("%s", SQUARE);
        }
        putchar('\n');
    }

    return 0;
}
