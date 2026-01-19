#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int tail);

int main(int argc, char *argv[]) {
    int tail = 10;
    if (argc > 1 && (*++argv)[0] == '-') {
        tail = (*argv)[1] - '0';
    }
    
    int nlines = 0;

    int running = 1;
    while (running == 1) {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            writelines(lineptr, nlines, tail);
        }
        else {
            running = 0;
        }
    }

    return 0;
}

#define MAXLEN 1000

int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len-1] = '\0';
            strcpy_s(p, MAXLEN, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines, int tail) {
    int i;

    for (i = 0; i < nlines; i++) {
        if (i >= nlines - tail) {
            printf("%s\n", lineptr[i]);
        }
    }
}

int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }
}