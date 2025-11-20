#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100

int getline(char*);
void reverse(char*);
int atoi2(char*);
void itoa2(int, char*);
int strindex(char*, char*);

int getop(char*);
#define OPERAND 0
#define OPERATOR 1

int main() {
    // getline
    char line1[MAXLINE];
    printf("Line length: %d (includes newline and null terminator)\n", getline(line1));
    printf("Text entered: %s\n", line1);

    // reverse
    char line2[MAXLINE];
    getline(line2);
    reverse(line2);
    printf("Your input in reverse: %s\n", line2);

    // atoi
    char line3[MAXLINE];
    getline(line3);
    printf("Your value subtracted by 100: %d\n", atoi2(line3) - 100);

    // itoa
    char line4[MAXLINE];
    int n1 = 123456789;
    itoa2(n1, line4);
    printf("%s is a string\n", line4);

    // strindex
    char line5[MAXLINE] = "The quick brown fox jumps over the lazy dog.";
    char line6[MAXLINE] = "jumps over";
    printf("String 2 occurs in string 1 at position %d\n", strindex(line5, line6));

    // getop
    char line7[MAXLINE];
    switch (getop(line7)) {
    case OPERAND:
        printf("You entered the operand %s\n", line7);
        break;
    case OPERATOR:
        printf("You entered the operator %s\n", line7);
        break;
    }

    return 0;
}

int getline(char *s) {
    char *start = s;

    while((*s++ = getchar()) != '\n');
    *s++ = '\n';
    *s = '\0';

    return s - start;
}

void reverse(char *s) {
    char *start = s;

    char *t = s;
    while (*++t != '\0');
    t--;

    char c;
    do {
        c = *s;
        *s = *t;
        *t = c;
    } while (++s < --t);

    s = start;
}

int atoi2(char *s) {
    int n = 0;
    while (*s >= '0' && *s <= '9') {
        n = 10 * n + (*s - '0');
        s++;
    }

    return n;
}

void itoa2(int n, char *s) {
    char *start = s;

    int sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        *s++ = '-';
    }

    *s++ = '\0';

    reverse(start);
}

int strindex(char *s, char *t) {
    char *start = s;

    while (*s != '\0') {
        char *u = s;
        while (*t == *u) {
            if (*(t+1) == '\0') {
                return (s - start);
            }
            t++;
            u++;
        }
        s++;
    }

    return -1;
}

int getop(char *s) {
    int c;

    while ((*s = c = getchar()) == ' ' || c == '\t');
    *++s = '\0';

    if (!isdigit(c) && c != '.') {
        return OPERATOR;
    }

    if (isdigit(c)) {
        while (isdigit(*s++ = c = getchar()));
    }
    if (c == '.') {
        while (isdigit(*s++ = c = getchar()));
    }
    *s = '\0';

    return OPERAND;
}