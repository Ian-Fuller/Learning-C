#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
    "_", 0,
    "string", 0,
    "//", 0,
    "/*", 0,
    "*/", 0,
    "#define", 0,
    "#include", 0
};

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);
int bruteforce(char *, struct key *, int);

int main() {
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if ((n = bruteforce(word, keytab, NKEYS)) >= 0) {
            keytab[n].count++;
        }
    }
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }

    return 0;
}

int bruteforce(char *word, struct key tab[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (strcmp(word, tab[i].word) == 0) {
            return i;
        }
    }

    return -1;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getch()));

    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c) && c != '#' && c != '/' && c != '*') {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch()) && *w != '/' && *w != '*') {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}