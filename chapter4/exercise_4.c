#include <stdio.h>

#define MAXVAL 100     /* максимальная глубина стека val */

int sp = 0;            /* следующая свободная позиция в стеке */
double val[MAXVAL];    /* стек операндов */


double top(void);
void push(double);
double pop(void);
void duplicate(void);
void swap(void);
void clear(void);


int main()
{
    for (int i = 0; i < 100; i += 10) {
        push(i);
    }
    
    printf("Top element: %f | size: %d\n", top(), sp);

    swap();
    printf("Swap: Top element: %f | size: %d\n", top(), sp);

    duplicate();
    printf("Duplicate: Top element: %f | size: %d\n", top(), sp);

    clear();
    printf("Clear: Top element: %f | size: %d\n", top(), sp);

    return 0;
}

/* get top element in stack */
double top(void)
{
    if (sp > 0) {
        return val[sp-1];
    }

    printf("error: stack empty\n");
    return 0.0;
}

/* push f in top */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
        return;
    }

    printf("error: stack full, can't push %g\n", f);
}

/* pop top element and return */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    }

    printf("error: stack empty\n");
    return 0.0;
}

/* duplicate top element */
void duplicate(void)
{
    if (sp < MAXVAL) {
        val[sp] = val[sp-1];
        ++sp;
        return;
    }

    printf("error: stack full, can't duplicate\n");
}

/* swap top two elements */
void swap(void)
{
    if (sp > 1) {
        double temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
        return;
    }

    printf("error: stack have few elements\n");
}

/* clear all data in stack*/
void clear(void)
{
    for (; sp > 0; --sp) {
        val[sp] = 0;
    }
}
