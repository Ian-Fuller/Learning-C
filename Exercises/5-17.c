/*
The wording for this exercise is rather confusing.
To put it simply, it is asking you to enable the program to sort something like:
Bob Smith 24
Mary Sue 20
Alex Gomez 36
based on the individual fields, like first name, last name, or age. Space being the obvious delimiter
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void myQsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int fieldIndex);

int numcmp(char*, char *);
int strcmp_ignorecase(char*, char*);
int strcmp_directory(char*, char*);
int strcmp_ignorecase_directory(char*, char*);

void getField(char *s, char *t, char delimiter, int index);

int reverse = 0;

int main(int argc, char *argv[]) {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        argv += argc - 1;

        argc += (argc == 1) ? 1 : 0;
        while (--argc > 0) {
            int numeric = 0;
            int fold = 0;
            int directory = 0;

            if (*argv[0] == '-') {
                int i;
                for (i = 0; i < strlen(*argv); i++) {
                    switch((*argv)[i]) {
                        case 'n':
                            numeric = 1;
                            break;
                        case 'r':
                            reverse = -1;
                            break;
                        case 'f':
                            fold = 1;
                            break;
                        case 'd':
                            directory = 1;
                            break;
                        default:
                            break;
                    }
                }
            }

            argv--;
            
            if (numeric == 1) {
                myQsort(lineptr, 0, nlines - 1, numcmp, argc - 1);
            }
            else if (fold == 1 && directory == 1) {
                myQsort(lineptr, 0, nlines - 1, strcmp_ignorecase_directory, argc - 1);
            }
            else if (fold == 1) {
                myQsort(lineptr, 0, nlines - 1, strcmp_ignorecase, argc - 1);
            }
            else if (directory == 1) {
                myQsort(lineptr, 0, nlines - 1, strcmp_directory, argc - 1);
            }
            else {
                myQsort(lineptr, 0, nlines - 1, strcmp, argc - 1);
            }

            reverse = 0;
        }

        writelines(lineptr, nlines, 0);
        return 0;
    }
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

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

void myQsort(void *v[], int left, int right, int (*comp)(void *, void *), int fieldIndex) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        char field1[MAXLEN];
        char field2[MAXLEN];
        getField(v[i], field1, ' ', fieldIndex);
        getField(v[left], field2, ' ', fieldIndex);
        if ((*comp)(field1, field2) * reverse < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    myQsort(v, left, last - 1, comp, fieldIndex);
    myQsort(v, last + 1, right, comp, fieldIndex);
}

/*
If I type John Baker 2000\n John Adams 2000\n Jay Zimmer 2000\n as input, first Adams and Baker get swapped and Zimmer stays in the same place
Next, Jay and John get swapped, but Adams is the one that gets swapped with Zimmer instead of Baker, and that's why last names are out of order
*/

void getField(char *s, char *t, char delimiter, int index) {
    char substrings[MAXLEN][MAXLEN];
    int i, j;

    i = 0;
    j = 0;
    while (*s != '\0') {
        if (*s != delimiter) {
            substrings[i][j] = *s;
            j++;
        }
        else {
            substrings[i][j] = '\0';
            i++;
            j = 0;
        }

        s++;
    }


    i = 0;
    while (substrings[index][i] != '\0') {
        t[i] = substrings[index][i];
        i++;
    }
    t[i] = '\0';
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
    printf("%s, %s\n", s1, s2);
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