#include <stdio.h>
#include <string.h>

#define MAX_LINES 5000
char *lineptr[MAX_LINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));

/* comparator functions */
int my_strcmp(char *, char *);
int my_alphstrcmp(char *, char *);

int my_numcmp(char *, char *);
int my_revnumcmp(char *s1, char *s2);

/* main */
int main(int argc, char *argv[]) {
    /* flags */
    int numeric = 0, recursive = 0, alph_register = 0;

    int c;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    recursive = 1;
                    break;
                case 'f':
                    alph_register = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    break;
            }
        }
    }

    /* main program */
    int nlines;
    if ((nlines = readlines(lineptr, MAX_LINES)) >= 0) {
        int (*pcomp)(char*, char*);
        if (recursive && numeric) {
            pcomp = my_revnumcmp;
        } else if (numeric) {
            pcomp = my_numcmp;
        } else if (alph_register) {
            pcomp = my_alphstrcmp;
        } else {
            pcomp = my_strcmp;
        }

        my_qsort((void **) lineptr, 0, nlines-1,
              (int (*)(void*, void*)) pcomp);

        printf("Answer:\n");
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* inpot output functions */
#define MAX_LEN 1000

int getline_c(char *s, int max_len);
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

void strcpy_c(char *s, char *line) {
    while (*s++ = *line++)
        ;
}

void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

/* qsort */
void my_qsort(void *v[], int left, int right,
           int (*comp)(void *, void *)) {
    void swap(void *v[], int i, int j);

    if (left >= right) {
        return;
    }
    swap(v, left, (left+right)/2);
    int last = left;

    for (int i = left+1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last-1, comp);
    my_qsort(v, last+1, right, comp);
}

/* custom compare functions for qsort */
char my_tolower(char);

int my_strcmp(char *s, char *t) {
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

int my_alphstrcmp(char *s, char *t) {
    for ( ; my_tolower(*s) != my_tolower(*t); s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

#include <stdlib.h>

int my_numcmp(char *s1, char *s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

int my_revnumcmp(char *s1, char *s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2) {
        return 1;
    } else if (v1 > v2) {
        return -1;
    } else {
        return 0;
    }
}

/* additional functions */
char my_tolower(char ch) {
    if ('A' <= ch && ch <= 'Z') {
        ch += 'a' - 'A';
    }
    return ch;
}

/* additional functions for qsort */
void swap(void *v[], int i, int j) {
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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
