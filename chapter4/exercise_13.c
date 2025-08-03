#include <stdio.h>

void reverse(char s[]);

int main()
{
    char s[] = "I love ice cream!";
    
    printf("Before: %s\n", s);
    reverse(s);
    printf("After: %s\n", s);

    return 0;
}

void reverse(char s[])
{
    static int l = 0, r = -1;
    int temp;

    if (r == -1) {
        while (s[++r] != '\0');
        --r;
    }

    if (l < r)  {
        temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
        reverse(s);
    } else {
        l = 0;
        r = -1;
    }
}
