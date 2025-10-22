#include <stdio.h>

#define MAXSTR 100

void strcat2(char*, char*);

int main() {
    char s1[MAXSTR] = "Hello ";
    char t1[MAXSTR] = "World!";

    strcat2(s1, t1);

    printf("%s\n", s1);

    char s2[MAXSTR] = "race";
    char t2[MAXSTR] = "car";

    strcat2(s2, t2);

    printf("%s\n", s2);

    char s3[MAXSTR] = "January ";
    char t3[MAXSTR] = "1st";

    strcat2(s3, t3);

    printf("%s\n", s3);

    return 0;
}

void strcat2(char *s, char *t) {
    while (*s++ != '\0');
    *s--;
    while ((*s++ = *t++) != '\0');
}