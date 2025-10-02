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

int getop(char[], int[], char[]);
void push(double);
double pop(void);

int getline(char line[]);
void ungets(char s[]);

int buf;
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int main() {
    int type;
    double op2;
    char s[MAXOP];
    char v[MAXOP]; // value

    double variables[26] = {0};

    int running = 1;
    while (running == 1) {
        int len = getline(s);

        int i[1];
        for (i[0] = 0; i[0] < len; i[0]++) {
            type = getop(s, i, v);
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
                push(atof(v));
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
            case ' ':
                // skip over whitespace
                break;
            case '\t':
                // skip over whitespace
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    }

    return 0;
}

int getop(char s[], int index[], char v[]) {
    int i, c;

    c = s[index[0]];

    // get variable assignment operator
    if (c >= 65 && c <= 90) {
        return ULETTER;
    }

    // get variable insertion operator
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
        while (isdigit(s[index[0]])) {
            c = s[index[0]];
            v[i++] = c;
            index[0]++;
        }
    }

    // collect fractional part
    if ((c = s[index[0]]) == '.') {
        v[i++] = '.';
        index[0]++;
        while (isdigit(s[index[0]])) {
            c = s[index[0]];
            v[i++] = c;
            index[0]++;
        }
    }

    v[i] = '\0';

    return NUMBER;
}

int getline(char line[]) {
    int len = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        line[len] = c;
        len++;
    }

    line[len++] = '\n';
    line[len] = '\0';

    return len;
}

void ungets(char s[]) {
    sp = 0;
    int i;
    for (i = 0; i < MAXVAL; i++) {
        val[i] = 0;
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
