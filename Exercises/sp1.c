#include <stdio.h>
#include <string.h>

char* getField(char *s, char delimiter, int index);

int main() {
    char *s1 = "Hello, World!";
    char *s2 = "one two three";

    printf("%s\n", getField(s1, ' ', 0));
    printf("%s\n", getField(s1, ' ', 1));
    printf("%s\n", getField(s2, ' ', 0));
    printf("%s\n", getField(s2, ' ', 1));
    printf("%s\n", getField(s2, ' ', 2));

    return 0;
}

char* getField(char *s, char delimiter, int index) {
    char *substrings[1000];
    char *start = substrings;

    int i = 0;
    do {
        if (*s != delimiter) {
            *substrings[i] = *s;
            i++;
        }
        else {
            *substrings[i] = '\0';
            // substrings++;
            i = 0;
        }
    } while (*++s != '\0');

    return *(start += index);
}