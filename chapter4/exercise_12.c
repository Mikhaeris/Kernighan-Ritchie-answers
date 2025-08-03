#include <stdio.h>

#define MAX_LINE 100

void itoa(int n, char s[]);

int main()
{
    int n = 123;
    char s[MAX_LINE];

    itoa(n, s);
    printf("Answer in string: %s\n", s);

    return 0;
}


void itoa(int n, char s[])
{
    static int i = 0;
    
    if (n < 0) {
        s[0] = '-';
        itoa(-n, s + 1);
        return;
    }

    if (n / 10 != 0) {
        itoa(n / 10, s);
    }

    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
