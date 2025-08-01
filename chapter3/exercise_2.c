#include <stdio.h>

#define SIZE 100

int escape(char s[], char t[]);
int unescape(char s[], char t[]);

int main()
{
    char t[SIZE] = "Hello\nWorld\t!";
    char s[SIZE];

    escape(s, t);

    puts("escape:\n");
    printf("\tBefore: %s\n\tAfter: %s\n", s, t);


    unescape(t, s);

    puts("\nunescape:\n");
    printf("\tBefore: %s\n\tAfter: %s\n", t, s);

    return 0;
}

int escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i)
    {
        switch (t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';
    return j;
}

int unescape(char s[], char t[])
{
    int i, j, prev;

    for (i = j = 0; t[i] != '\0'; ++i)
    {
        switch (t[i])
        {
            case '\\':
                switch (t[++i])
                {
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';
    return j;
}
