#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "The quick red fox jumped over the lazy dog.";
	char s2[] = "Red leather, yellow leather.";

	squeeze(s1, s2);

    int i = 0;
	while (s1[i] != '\0') {
        printf("%c", s1[i]);
        i++;
    }

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i = 0;
    int k = 0;
    while (s1[i] != '\0') {
        int match = 0;
        int j = 0;
        while (s2[j] != '\0') {
            if (s1[i] == s2[j]) {
                match = 1;
            }
            j++;
        }
        if (match == 0) {
            s1[k] = s1[i];
            // s1[i] = '_';
            k++;
        }
        i++;
    }
    s1[k] = '\0';
}