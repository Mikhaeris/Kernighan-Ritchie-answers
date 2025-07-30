#include <stdio.h>
#include <limits.h>

unsigned int rightrot(unsigned int x, int n);

int main()
{
    unsigned int x = 11;
    int n = 34;
    
    printf("Answer: %u", rightrot(x, n));

    return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
#if 0 /* first version */

    unsigned int offset = sizeof(x) * CHAR_BIT;
    
    n %= offset;

    unsigned int mask = ~(~0u << n);
    unsigned int row = x & mask;

    return (row << (offset - n)) | (x >> n);

#else /* second version */
    
    unsigned int offset = sizeof(x) * CHAR_BIT;

    n %= offset;

    return (x << (offset - n)) | (x >> n);

#endif
}
