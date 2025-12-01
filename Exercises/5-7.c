#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char sotrage[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getline(char *, int);
void strcpy2(char *s, char *t);

int main() {
    int nlines;
    char storage[ALLOCSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, storage)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines, char storage[]) {
    int len, nlines;
    char line[MAXLEN];
    char *storagep;

    nlines = 0;
    storagep = storage;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return -1;
        }
        else {
            line[len-1] = '\0';
            strcpy2(storagep, line);
            lineptr[nlines++] = storagep;
            while (len-- > 0) {
                storagep++;
            }
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap (char *v[], int i, int j);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void strcpy2(char *s, char *t) {
    while ((*s++ = *t++));
}
