#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float*);

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int main () {
    float myFloat = 0;

    for (;;) {
        getfloat(&myFloat);
        printf("You entered: %f\n", myFloat);
    }

    return 0;
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

int getfloat(float *pn) {
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' ) {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
            c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
        int place;
        for (place = 1; isdigit(c); c = getch(), place *= 10) {
            *pn = 10 * *pn + (c - '0');
        }
        *pn /= place;
    }
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}