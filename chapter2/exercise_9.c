#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
    unsigned int x = 3;

    printf("Answer: %d\n", bitcount(x));
    
    return 0;
}

int bitcount(unsigned int x)
{
    int ans;

    ans = 0;
    while (x)
    {
        x &= x-1;
        ++ans;
    }

    return ans;
}
