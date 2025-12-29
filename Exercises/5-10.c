#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'

#define BUFSIZE 100

#define MAXVAL  100

int getop(char[], char[]);
void push(double);
double pop(void);

void strcpy2(char*, char*);

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXOP];

    while (--argc > 0 && (type = getop(s, *++argv)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            push(pop() * -1);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            }
            else {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((int)pop() % (int)op2);
            }
            else {
                printf("error: zero divisor\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    printf("%.8g\n", pop());

    return 0;
}

int getop(char s[], char arg[]) {
    strcpy2(s, arg);

    if (isdigit(s[0])) {
        return NUMBER;
    }
    else {
        return s[0];
    }
}

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void strcpy2(char *s, char *t) {
    while ((*s++ = *t++));
}