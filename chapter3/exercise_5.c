#include <stdio.h>

#define MAX_LINE 100

void itob(int n, char s[], int b);

void reverse(char s[]);

int main()
{
    int n, b;
    char s[MAX_LINE];
     
    printf("Enter num: ");
    scanf("%d", &n);
    printf("Enter system: ");
    scanf("%d", &b);

    itob(n, s, b);
    printf("\nNum: \t%d\nTo sys: %d\nAnswer: %s\n", n, b, s);

    return 0;
}


void itob(int n, char s[], int b)
{
    int i, rem;
    i = 0;

    if (b < 2 || b > 32)
    {
        s[i] = '\0';
        return;
    }

    while (rem = (n % b))
    {
        s[i++] = (rem > 9) ? rem - 10 + 'A' : rem + '0';
        n /= b;
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j, temp;

    i = j = 0;
    while (s[j++] != '\0');

    j -= 2;
    while (i < j)
    {
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}
