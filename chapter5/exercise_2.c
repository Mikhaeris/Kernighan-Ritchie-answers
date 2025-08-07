#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getfloat(float *pn);

int main()
{
    int getfloat(float *);
    float array[SIZE] = {0.0};
    float temp;

    for (int n = 0; n < SIZE && getfloat(&temp) != EOF;) {
        if (temp == 0) {
            continue;
        }

        array[n++] = temp;
    }

    puts("\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%f ", array[i]);
    }

    return 0;
}

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        *pn = 0.0;
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int next = getch();

        if (!isdigit(next)) {
            ungetch(next);
            ungetch(c);
            return 0;
        }

        c = next;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    double power = 1.0;
    if (c == '.') {
        c = getch();
        for (; isdigit(c); c = getch()) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
    }
    *pn = sign * (*pn / power);;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf ("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
