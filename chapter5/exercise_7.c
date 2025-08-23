#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char p[MAXLEN], line[MAXLEN];

    nlines = 0;
    while ((len = getline_c(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}
