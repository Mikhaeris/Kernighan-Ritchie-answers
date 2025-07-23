#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 30;
    step = 1;

    celsius = lower;
    printf("celsius fahr\n");
    while (celsius <= upper)
    {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%6.1f %5.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
