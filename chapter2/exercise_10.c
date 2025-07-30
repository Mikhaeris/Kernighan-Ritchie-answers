#include <stdio.h>

void lower(char s[]);

int main()
{
    char s[] = "I Love Ice Cream!";

    puts(s);
    lower(s);
    puts(s);

    return 0;
}

void lower(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
    {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z' ) ?
                s[i] - 'A' + 'a' : s[i];
    }
}
