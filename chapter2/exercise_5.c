#include <stdio.h>

int any(const char s1[], const char s2[]);

int main()
{
    char s1[] = "breabsdcdefg";
    char s2[] = "ae";

    printf("First position: %d", any(s1, s2));

    return 0;
}

int any(const char s1[], const  char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i)
    {
        j = 0;
        for (; s2[j] != '\0' && s2[j] != s1[i]; ++j);

        if (s2[j] != '\0')
        {
            return i;
        }
    }

    return -1;
}
