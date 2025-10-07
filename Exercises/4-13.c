#include <stdio.h>
#include <string.h>

void reverse(char[]);

int main() {
    char s1[] = "Hello, World!";
    reverse(s1);
    printf("%s\n", s1);

    char s2[] = "An even number of characters";
    reverse(s2);
    printf("%s\n", s2);

    char s3[] = "An odd number of characters";
    reverse(s3);
    printf("%s\n", s3);

    return 0;
}

void reverse(char s[]) {
    static int c = 0, i = 0;

    c = s[i];
    s[i] = s[strlen(s)-1 - i];
    s[strlen(s)-1 - i] = c;

    if (i < strlen(s)-1 - i) {
        i++;
        reverse(s);
    }

    c = 0;
    i = 0;
}