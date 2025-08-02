#include <stdio.h>
#include <limits.h>

#define MAX_LINE 100

void itoa(int n, char s[], int width);

void reverse(char s[]);

int main()
{
    int n;
    char s[MAX_LINE];

    n = INT_MIN;
    itoa(n, s, 15);
    printf("Num: \t|%d\nString: |%s\n", n, s);

    return 0;
}

/* INT_MIN = -2147483648
 * INT_MAX =  2147483647
 *                     1
 *
 * UINT_MAX = 4294967295 */
void itoa(int n, char s[], int width)
{
    int i;
    unsigned int num;
    
    num = (n < 0) ? -(unsigned int)n : n; 

    i = 0;
    do
    {
        s[i++] = num % 10 + '0';
    }
    while ((num /= 10) > 0);

    if (n < 0)
    {
        s[i++] = '-';
    }
    
    while (i < width)
    {
        s[i++] = ' ';
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
