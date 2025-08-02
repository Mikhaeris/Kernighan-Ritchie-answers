#include <stdio.h>
#include <math.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
    double atof(char s[]);
    char s[] = "123.35e+6";
    
    printf("Answer: %.15f", atof(s));

    return 0;
}

double atof(char s[])
{
    double val, power, exp;
    int i, sign;

    for (i = 0; isspace(s[i]); ++i);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        ++i;
    }

    for (val = 0.0; isdigit(s[i]); ++i)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        ++i;
    }

    for (power = 1.0; isdigit(s[i]); ++i)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i++] == 'e')
    {
        exp = pow(10, s[++i] - '0');
        --i;
        if (s[i] == '-')
        {
            val /= exp;
        }
        else if (s[i] == '+')
        {
            val *= exp; 
        }
        else
        {
            val *= pow(10, s[i] - '0');
        }
    }   

    return sign * val / power;
}
