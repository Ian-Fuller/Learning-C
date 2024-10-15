#include <stdio.h>

#define LIMIT 100

int main() {
    char s[LIMIT];

    int c;
    int i;
    for (i = 0; (c = getchar()) != '\n'; ++i) {
        if (i < LIMIT - 1) {
            if (c != EOF) {
                s[i] = c;
            }
            else {
                c = '\n';
            }
        }
        else {
            c = '\n';
        }
    }

    int j;
    for (j = 0; j < i - 1; ++j) {
        printf("%c", s[j]);
    }
}