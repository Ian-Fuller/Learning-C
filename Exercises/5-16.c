#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void myQsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char*, char *);
int strcmp_ignorecase(char*, char*);
int strcmp_directory(char*, char*);
int strcmp_ignorecase_directory(char*, char*);

int main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;
    int directory = 0;

    while (--argc > 0) {
        ++argv;
        if (strcmp(*argv, "-n") == 0) {
            numeric = 1;
        }
        if (strcmp(*argv, "-r") == 0) {
            reverse = 1;
        }
        if (strcmp(*argv, "-f") == 0) {
            fold = 1;
        }
        if (strcmp(*argv, "-d") == 0) {
            directory = 1;
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myQsort((void **)lineptr, 0, nlines-1, (int (*)(void*, void*))(
            numeric ? numcmp : (
                (fold && directory) ? strcmp_ignorecase_directory : (
                    fold ? strcmp_ignorecase : (
                        directory ? strcmp_directory : strcmp
        )))));
        writelines(lineptr, nlines, reverse);
        return 0;
    }
    else {
        printf("input too big to sort\n");
        return 1;
    }
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

void writelines(char *lineptr[], int nlines, int reverse) {
    int i;

    if (reverse == 0) {
        for (i = 0; i < nlines; i++) {
            printf("%s\n", lineptr[i]);
        }
    }
    else if (reverse == 1) {
        for (i = nlines - 1; i >= 0; i--) {
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

void myQsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    myQsort(v, left, last - 1, comp);
    myQsort(v, last + 1, right, comp);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2) {
        return -1;
    }
    else if (v1 > v2) {
        return 1;
    }
    else {
        return 0;
    }
}

int strcmp_ignorecase(char *s1, char * s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = *s1;
        char c2 = *s2;

        if (c1 >= 97 && c1 <= 122) {
            c1 -= 32;
        }
        if (c2 >= 97 && c2 <= 122) {
            c2 -= 32;
        }

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }
    return 0;
}

int strcmp_directory(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = *s1;
        char c2 = *s2;

        while (!(c1 >= 65 && c1 <= 90 || c1 >= 97 && c1 <= 122 || c1 == ' ' || c1 == '\t')) {
            s1++;
            c1 = *s1;
        }
        while (!(c2 >= 65 && c2 <= 90 || c2 >= 97 && c2 <= 122 || c2 == ' ' || c2 == '\t')) {
            s2++;
            c2 = *s2;
        }

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }
    return 0;    
}

int strcmp_ignorecase_directory(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = *s1;
        char c2 = *s2;

        while (!(c1 >= 65 && c1 <= 90 || c1 >= 97 && c1 <= 122 || c1 == ' ' || c1 == '\t')) {
            s1++;
            c1 = *s1;
        }
        while (!(c2 >= 65 && c2 <= 90 || c2 >= 97 && c2 <= 122 || c1 == ' ' || c1 == '\t')) {
            s2++;
            c2 = *s2;
        }

        if (c1 >= 97 && c1 <= 122) {
            c1 -= 32;
        }
        if (c2 >= 97 && c2 <= 122) {
            c2 -= 32;
        }

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }
    return 0;    
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}