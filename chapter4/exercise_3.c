#include <stdio.h>
#include <stdlib.h>  /* для объявления atof () */

#define MAXOP 100    /* максимальный размер операнда или знака */
#define NUMBER '0'   /* сигнал, что обнаружено число */

int getop(char s[]);
void push(double);
double pop(void);

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 != 0.0) {
                    push(op1 - ((long)(op1 / op2) * op2));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

#define MAXVAL 100     /* максимальная глубина стека val */
int sp = 0;            /* следующая свободная позиция в стеке */
double val[MAXVAL];    /* стек операндов */

/* push: помещает число f в стек операндов */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: извлекает и возвращает верхнее число из стека */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: извлекает следующий операнд или знак операции */
int getop(char s[])
{
    int i = 0, c, next;

    while ((c = getch()) == ' ' || c == '\t');

    s[i++] = c;
    s[i] = '\0';
    if (c == '-' || c == '+') {
        next = getch();
        if (isdigit(next) || next == '.') {
            s[i++] = next;
            s[i] = '\0';
            c = next;
        } else {
            ungetch(next);
            return c;
        }
    }

    if (isdigit(c) || c == '.') {
        /* накопление целой части */
        while (isdigit(s[i++] = c = getch()));

        if (c =='.') {
            /* накопление дробной части */
            while (isdigit(s[i++] = c = getch()));
        }

        s[i] = '\0';
        if (c != EOF) {
            ungetch(c);
        }

        return NUMBER;
    }

    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];   /* буфер для ungetch */
int bufp = 0;         /* следующая свободная позиция в buf */

int getch(void) /* ввод символа (возможно, возвращенного в поток) */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* возвращение символа в поток ввода */
{
    if (bufp >= BUFSIZE) {
        printf ("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
