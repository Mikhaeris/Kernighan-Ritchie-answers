void itoa(int n, char *s)
{
    unsigned int num = (n < 0) ? -(unsigned int)n : n; 

    do {
        *s++ = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (n < 0) {
        *s++ = '-';
    }

    *s = '\0';
    reverse(s);
}
