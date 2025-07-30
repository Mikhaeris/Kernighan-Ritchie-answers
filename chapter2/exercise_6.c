#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main()
{
    unsigned int x = 199, y = 7;
    int p = 5, n = 3;
    
    printf("Answer: %u\n", setbits(x, p, n, y));

    return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int mask = ~(~0U << n);

    return  ((y & mask) << (p+1-n)) | (x & ~(mask << (p+1-n)));
}
