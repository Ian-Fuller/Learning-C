#include <stdio.h>

int strend(char*, char*);

int main() {
    char s1[] = "extend";
    char s2[] = "end";
    char s3[] = "and";
    char s4[] = "or";
    char s5[] = "d";
    char s6[] = "tend";

    if (strend(s1, s2)) {
        printf("String 1 ends with string 2.\n");
    }
    else {
        printf("String 1 does not end with string 2.\n");
    }

    if (strend(s1, s3)) {
        printf("String 1 ends with string 3.\n");
    }
    else {
        printf("String 1 does not end with string 3.\n");
    }

    if (strend(s1, s4)) {
        printf("String 1 ends with string 4.\n");
    }
    else {
        printf("String 1 does not end with string 4.\n");
    }

    if (strend(s1, s5)) {
        printf("String 1 ends with string 5.\n");
    }
    else {
        printf("String 1 does not end with string 5.\n");
    }

    if (strend(s1, s6)) {
        printf("String 1 ends with string 6.\n");
    }
    else {
        printf("String 1 does not end with string 6.\n");
    }

    return 0;
}

int strend(char *s, char *t) {
    // save pointer position of t so it can be compared to its later position
    char *tStart = t;

    // go to the end of each string
    while (*++s != '\0');
    while (*++t != '\0');

    // decrement through each string until a difference is found
    while (*--s == *--t);

    // if t has returned to its start, that means its entirety matches with the end of the larger string
    if (++t == tStart) {
        return 1;
    }

    return 0;
}