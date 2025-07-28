#include <stdio.h>
#include <math.h>

long htoi(char s[]);

int main()
{
    char test1[] = "0x1A3";
    printf("%s: %ld\n", test1, htoi(test1));

    char test2[] = "-0x1A3";
    printf("%s: %ld\n", test2, htoi(test2));

    return 0;
}

long htoi(char s[])
{
    int i, digit, sign;
    long ans;
    
    if (s[0] != '-')
    {
        i = 2;
        sign = 1;
    }
    else
    {
        i = 3;
        sign = -1;
    }

    ans = digit = 0;
    for (; s[i] != '\0'; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            digit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            digit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
           digit = s[i] - 'A' + 10;
        }
        else
        {
            return -1;
        }

        ans = ans * 16 + digit;
    }

    return sign * ans;
}
