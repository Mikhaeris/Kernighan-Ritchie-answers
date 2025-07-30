#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main()
{
    unsigned int x = 13;
    int p = 2, n = 2;
    
    printf("Answer: %u", invert(x, p, n));

    return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int mask = ~(~0u << n) << p-n+1;
    return x ^ mask;
}
