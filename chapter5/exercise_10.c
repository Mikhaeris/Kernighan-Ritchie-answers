#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'

int get_arg(char *s);

void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("error: too few arguments\n");
        return 1;
    }

    double op1, op2;
    while (--argc > 0) {
        switch (get_arg(*++argv)) {
            case NUMBER:
                push(atof(*argv));
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
                if (op2 != 0.0)
                    push(op1 - ((long)(op1 / op2) * op2));
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }

    printf("Answer: %.8g\n", pop());

    return 0;
}

/* simple stack in stack :) */
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* parse argv */
int get_arg(char *s) {
    if (*s == '-' || *s == '+') {
        int next = *(s+1);
        if (isdigit(next) || next == '.') {
           return NUMBER; 
        } else {
            return *s;
        }
    }

    if (isdigit(*s)) {
        return NUMBER;
    }

    return *s;
}
