#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 6

int getline(char line[]);
void clearstr(char s[]);
int htoi(char s[]);

int main() {
    char line[SIZE];
    int len;

    while ((len = getline(line)) > 0) {
        printf("%d\n", htoi(line));
        clearstr(line);
    }

    return 0;
}

int getline(char line[]) {
    int len = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        line[len] = c;
        len++;
    }

    return len;
}

void clearstr(char s[]) {
    int i;
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        s[i] = '\0';
    }
}

int htoi(char s[]) {
    int len = strlen(s) - 1;
    int total = 0;

    int i;
    for (i = len; i >= 0; i--) {
        if (isdigit(s[i])) {
            total += (s[i] - '0') * (int)pow(16, len - i);
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            total += (s[i] - 'A' + 10) * (int)pow(16, len - i);
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            total += (s[i] - 'a' + 10) * (int)pow(16, len - i);
        }
    }

    return total;
}