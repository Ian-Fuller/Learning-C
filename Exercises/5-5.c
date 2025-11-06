#include <stdio.h>

char *strncpy2(char*, char*, int);
char *strncat2(char*, char*, int);
int strncmp2(char*, char*, int);

int main() {
    char s1[] = "Hello, World!";
    char s2[] = "G'bye, mate!";
    printf("%s\n", strncpy2(s1, s2, 5));

    char s3[] = "Marco ";
    char s4[] = "Polo player";
    printf("%s\n", strncat2(s3, s4, 4));

    char s5[] = "Catalog";
    char s6[] = "Caterpillar";
    printf("%d, %d, %d\n", strncmp2(s5, s6, 3), strncmp2(s5, s6, 4), strncmp2(s6, s5, 4));

    return 0;
}

char *strncpy2(char *s, char *t, int n) {
    // save beginning of s so it can be returned later, since decrementing the pointer back to the right position would be a pain
    char *start = s;

    // replace the characters in s with the characters in t until n is reached
    int i = 0;
    while ((*s++ = *t++) != '\0' && i++ < n);

    return start;
}

char *strncat2(char *s, char *t, int n) {
    // save beginning of s so it can be returned later, since decrementing the pointer back to the right position would be a pain
    char *start = s;

    // go to the end of s, exclusing the null terminator
    while (*++s != '\0');

    // append in characters from t to s
    int i = 0;
    while ((*s++ = *t++) != '\0' && i++ < n);

    *s = '\0';

    return start;
}

int strncmp2(char *s, char *t, int n) {
    // loop through s and t until they are unequal, or one of them is a null terminator, or i has reached n
    int i = 0;
    while (i++ < n-1 && *s++ == *t++ && *s != '\0' && *t != '\0');
    // note that it's crucial to place i++ < n-1 at the beginning, otherwise s and t may be over-incremented when the loop terminates
    // n also needs to be subtracted by 1, otherwise s and t will be one value higher than they need to be

    // compare the current values of *s and *t
    if (*s == *t) {
        return 0;
    }
    else if (*s > *t) {
        return 1;
    }
    else if (*s < *t) {
        return -1;
    }

    return 0;
}