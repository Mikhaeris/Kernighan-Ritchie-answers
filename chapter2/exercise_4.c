#include <stdio.h>

void squeeze(char s1[], const char s2[]);

int main()
{
    char s1[] = "abeareabsdcdefg";
    char s2[] = "aeb";
    
    printf("Symbols: %s\nBefore: %s\n", s2, s1);

    squeeze(s1, s2);

    printf("After: %s\n", s1);

    return 0;
}

void squeeze(char s1[], const char s2[])
{
    int i, j, p;

    p = 0;
    for (i = 0; s1[i] != '\0'; ++i)
    {
        j = 0;
        for (; s2[j] != '\0' && s2[j] != s1[i]; ++j);

        if (s2[j] == '\0')
        {
            s1[p++] = s1[i];
        }
    }

    s1[p] = '\0';
}
