#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void itoa(int, int[], char[]);

int main() {
    int i[] = { 0 };

    int n1 = 123;
    char s1[MAXLEN];
    itoa(n1, i, s1);
    printf("%s\n", s1);

    int n2 = 576892;
    char s2[MAXLEN];
    i[0] = 0;
    itoa(n2, i, s2);
    printf("%s\n", s2);

    int n3 = -50;
    char s3[MAXLEN];
    i[0] = 0;
    itoa(n3, i, s3);
    printf("%s\n", s3);

    return 0;
}

void itoa(int n, int i[], char s[]) {
    if (n < 0) {
        s[i[0]++] = '-';
        n = n * -1;
    }

    if (n / 10) {
        itoa(n / 10, i, s);
    }
    s[i[0]++] = n % 10 + '0';
}