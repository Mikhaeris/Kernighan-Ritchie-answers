#include <stdio.h>

#define MAX_LINES 1000

void parse_args(int argc, char *argv[], int *n);

int readlines(char *lineptr[], int maxlines);
int writelines(char *lineptr[], int nlines, int n);

int main(int argc, char *argv[]) {
    int n = 10;
    parse_args(argc, argv, &n);
   
    char *lineptr[MAX_LINES];
    int nlines = readlines(lineptr, MAX_LINES);

    if (n < 1 || n > nlines) {
        n = 10;
    }

    printf("\nAnswer:\n");
    writelines(lineptr, nlines, n); 

    return 0;
}

/* parse args */
int get_num(char *s);

void parse_args(int argc, char *argv[], int *n) {
    int c;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'n':
                    *n = get_num(*++argv);
                    --argc;
                    break;
                default:
                    printf("find: illegal option %c\n:", c);
                    break;
            }
        }
    }
}

int get_num(char *s) {
    int num = 0;

    while (*s) {
        num *= 10;
        num += *s++ - '0';
    }

    return num;
}

/* read lines in *lineptr[] */
#define MAX_LEN 1000

int getline_c(char *s, int max_len);
void printline_c(char *s);
void strcpy_c(char *s, char *line);

char *alloc(int n);

int readlines(char *lineptr[], int maxlines) {
    char *p, line[MAX_LEN];

    int len;
    int nlines = 0;
    while ((len = getline_c(line, MAX_LEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy_c(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

int getline_c(char *s, int lim) {
    char *st = s;
    while (--lim > 0 && (*st = getchar()) != EOF && *st != '\n') {
        st++;
    }

    if (*st == '\n') {
        *st++ = '\0';
    }

    *st = '\0';
    return st-s;
}

int writelines(char *lineptr[], int nlines, int n) {
    for (int i = nlines - n; i < nlines; i++) {
        printline_c(lineptr[i]); 
    }
}

void printline_c(char *s) {
    while (*s) {
        putchar(*s++);
    }

    putchar('\n');
}

void strcpy_c(char *s, char *line) {
    while (*s++ = *line++)
        ;
}

/* custom allocator in stack */
#define ALLOC_SIZE 10000

static char allocbuf[ALLOC_SIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + ALLOC_SIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *p) {
    if (p > allocbuf && p < allocbuf + ALLOC_SIZE) {
        allocp = p;
    }
}
