#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP   100
#define NUMBER  '0'
#define ULETTER '1'
#define LLETTER '2'

#define BUFSIZE 100

#define MAXVAL  100

int getop(char[]);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);
void ungets(char s[]);

char buf;
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int main() {
    int type;
    double op2;
    char s[MAXOP];

    double variables[26] = {0};

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case 'w': // print - changed from p to w for write
            double save = pop();
            push(save);
            printf("%g\n", save);
            break;
        case 'd': // duplicate
            double duplicate = pop();
            push(duplicate);
            push(duplicate);
            break;
        case 's': // swap
            double swap1 = pop();
            double swap2 = pop();
            push(swap1);
            push(swap2);
            break;
        case 'c': // clear
            while (sp >= 0) {
                val[sp--] = 0.0;
            }
            break;
        case 't': // sine - t for theta
            push(sin(pop()));
            break;
        case 'e': // exponential
            push(exp(pop()));
            break;
        case 'p': // power
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 'u': // ungets
            ungets(s);
            break;
        case NUMBER:
            push(atof(s));
            break;
        case ULETTER:
            variables[(int)s[0] - 65] = pop();
            break;
        case LLETTER:
            push(variables[(int)s[0] - 97]);
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

    return 0;
}

int getop(char s[]) {
    int i, c;

    // continue getting new characters from the user until a non-whitespace value is found
    while((s[0] = c = getch()) == ' ' || c == '\t');

    // since the function is only supposed to get one charatcer, place a terminator at the second index, so only the first character remains
    s[1] = '\0';
    
    // get variable operator
    if (c >= 65 && c <= 90) {
        return ULETTER;
    }

    if (c >= 97 && c <= 122) {
        return LLETTER;
    }

    // exit function if the character is anything that shouldn't be in a non-negative decimal value
    if (!isdigit(c) && c != '.') {
        return c;
    }

    // collect integer part
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }

    // collect fractional part
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

int getch(void) {
    if (bufp == 1) {
        bufp = 0;
        return buf;
    }
    return getchar();
}

void ungetch(int c) {
    bufp = 1;
    buf = c;
}

void ungets(char s[]) {
    int i = strlen(s);
    while (i > 0) {
        ungetch(s[--i]);
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