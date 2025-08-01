#include <stdio.h>

#define SIZE 1000

void expand(char s1[], char s2[]);

int main()
{
    char s1[SIZE] = "a-/asdajda-z0-9asadasd b-e-f-j-z";
    char test1[] = "a-z";
    char s2[SIZE];

    expand(s1, s2);
    
    printf("Before: %s\n", s1);
    printf("After:  %s\n", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    int k;

    k = 0;
    for (i = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i+1] == '-' && s1[i] < s1[i+2])
        {
            for (j = s1[i]; j < s1[i+2]; ++j)
            {
                s2[k++] = j;
            }
            ++i;
            continue;
        }

        s2[k++] = s1[i];
    }

    s2[k] = '\0';
}
