#include <stdio.h>

#define SIZE 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char s[SIZE];
    char t1[SIZE] = "test \n \t \\ test\n\0";
    char t2[SIZE] = "test \\n \\t \\\\ test\\n\0";

    escape(s, t1);
    printf("Before: %s\nEscaped: %s\n", t1, s);
    unescape(s, t2);
    printf("Before: %s\nUnescaped: %s\n", t2, s);

    return 0;
}

void escape(char s[], char t[]) { // /n to //n
    int i = 0;
    int j = 0;
    while (t[i] != '\0') {
        switch(t[i]) {
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                s[++j] = 't';
                break;
            case '\\':
                s[j] = '\\';
                s[++j] = '\\';
                break;
            // more cases could be added, but would be unnecessary in the case of showing that the program conceptually works
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) { // //n to /n
    int i = 0;
    int j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            switch(t[i + 1]) {
                case 'n':
                    s[j] = '\n';
                    i++;
                    break;
                case 't':
                    s[j] = '\t';
                    i++;
                    break;
                case '\\':
                    s[j] = '\\';
                    i++;
                    break;
                // more cases could be added, but would be unnecessary in the case of showing that the program conceptually works
                default:
                    s[j] = t[i];
                    break;
            }
        }
        else {
            s[j] = t[i];
        }
        i++;
        j++;
    }
    s[j] = '\0';
}