#include <stdio.h>

int main()
{
    int c;
    unsigned long long count_space, count_tab, count_end_line;

    count_space    = 0;
    count_tab      = 0;
    count_end_line = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++count_space;
        }
        if (c == '\t')
        {
            ++count_tab;
        }
        if (c == '\n')
        {
            ++count_end_line;
        }
    }

    printf("Count spaces: %llu\n"
           "Count tabs: %llu\n"
           "Count end of line: %llu\n",
           count_space, count_tab, count_end_line);
    return 0;
}
