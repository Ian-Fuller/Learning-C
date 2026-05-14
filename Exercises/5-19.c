#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

// // dcl
// int main() {
//     while (gettoken() != EOF) {
//         strcpy_s(datatype, MAXTOKEN, token);
//         out[0] = '\0';
//         dcl();
//         if (tokentype != '\n') {
//             printf("syntax error\n");
//             while (gettoken() != '\n');
//         }
//         printf("%s: %s %s\n", name, out, datatype);
//     }
//     return 0;
// }

// undcl
int main() {
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy_s(out, MAXTOKEN,  token);
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS) {
                strcat_s(out, MAXTOKEN, token);
            }
            else if (type == '*') {
                sprintf(temp, "(*%s)", out);
                strcpy_s(out, MAXTOKEN, temp);
            }
            else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy_s(out, MAXTOKEN, temp);
            }
            else {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

void dcl(void) {
    int ns;

    for (ns = 0; gettoken() == '*';) {
        ns++;
    }
    dirdcl();
    while (ns-- > 0) {
        strcat_s(out, MAXTOKEN, " pointer to");
    }
}

void dirdcl(void) {
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            while (gettoken() != ')');
        }
    }
    else if (tokentype == NAME) {
        strcpy_s(name, MAXTOKEN, token);
    }
    else {
        printf("error: expected name or (dcl)\n");
        dcl();
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strcat_s(out, MAXTOKEN, " function returning");
        }
        else {
            strcat_s(out, MAXTOKEN, " array");
            strcat_s(out, MAXTOKEN, token);
            strcat_s(out, MAXTOKEN, " of");
        }
    }
}

int gettoken(void) {
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t');

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy_s(token, MAXTOKEN, "()");
            return tokentype = PARENS;
        }
        else {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';);
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch());) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else {
        return tokentype = c;
    }
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