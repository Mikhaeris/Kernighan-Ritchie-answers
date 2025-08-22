#include <stdio.h>

void reverse(char *s);

int main()
{
    char s[] = "i love ice cream!";

    printf("Before: %s\n", s);
    reverse(s);
    printf("After: %s", s);
}

void reverse(char *s)
{
    char *se = s;
    while (*se != '\0') {
        ++se;
    }
    
    --se;
    while (s < se) {
        char temp = *s;
        *s++ = *se;
        *se-- = temp;
    }
}
