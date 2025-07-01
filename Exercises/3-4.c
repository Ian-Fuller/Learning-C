/*
The program normally doesn't work, because, in two's complement, the negative range is one value further away from 0 than the positive range, as 0 is
included in said positive range. For an 8-bit integer, if n were to equal something like -128, negating it would result in a value of 128, which is 1
outside the range. This would cause the integer to loop back around to being a negrative integer.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char []);
void reverse(char s[]);

int main() {
    int i1 = 12345;
    char s1[] = "";
    itoa(i1, s1);
    printf("%s\n", s1);

    int i2 = -6789;
    char s2[] = "";
    itoa(i2, s2);
    printf("%s\n", s2);

    int i3 = INT_MAX;
    char s3[] = "";
    itoa(i3, s3);
    printf("%s\n", s3);

    int i4 = INT_MIN;
    char s4[] = "";
    itoa(i4, s4);
    printf("%s\n", s4);

    int i5 = INT_MIN + 1;
    char s5[] = "";
    itoa(i5, s5);
    printf("%s\n", s5);

    return 0;
}

void itoa(int n, char s[]) {
    int i, sign, min;

    min = 0;
    if (n == INT_MIN) {
        n = INT_MIN + 1;
        min = 1;
    }

    if ((sign = n) < 0) {
        n = -n; // The issue occurs here. If you flip INT_MIN, it will be 1 over the range of INT_MAX
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    if (min == 1) {
        s[0]++;
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}