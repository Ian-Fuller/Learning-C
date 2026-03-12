#include <stdio.h>
#include <string.h>

#define SIZE 1000

void getField(char *s, char *t, char delimiter, int index);

int main() {
    char *s1 = "Hello, World!";
    char *s2 = "one two three";

    char output[SIZE];

    getField(s1, output, ' ', 0);
    printf("%s\n", output);
    getField(s1, output, ' ', 1);
    printf("%s\n", output);
    getField(s2, output, ' ', 0);
    printf("%s\n", output);
    getField(s2, output, ' ', 1);
    printf("%s\n", output);
    getField(s2, output, ' ', 2);
    printf("%s\n", output);

    return 0;
}

void getField(char *s, char *t, char delimiter, int index) {
    char substrings[SIZE][SIZE];
    int i, j;

    i = 0;
    j = 0;
    while (*s != '\0') {
        if (*s != delimiter) {
            substrings[i][j] = *s;
            j++;
        }
        else {
            substrings[i][j] = '\0';
            i++;
            j = 0;
        }

        s++;
    }


    i = 0;
    while (substrings[index][i] != '\0') {
        t[i] = substrings[index][i];
        i++;
    }
    t[i] = '\0';
}