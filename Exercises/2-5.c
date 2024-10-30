#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[] = "The quick red fox jumped over the lazy dog.";
	char s2[] = "Red leather, yellow leather.";

    int pos = any(s1, s2);
    if (pos == -1) {
        printf("s1 does not contain any characters from s2.\n");
    }
    else {
        printf("A character from s2 first occurs at: %d in s1.\n", any(s1, s2));
    }

    return 0;
}

int any(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0') {
        int match = 0;
        int j = 0;
        while (s2[j] != '\0') {
            if (s1[i] == s2[j]) {
                match = 1;
            }
            j++;
        }
        if (match == 1) {
            return i;
        }
        i++;
    }

    return -1;
}