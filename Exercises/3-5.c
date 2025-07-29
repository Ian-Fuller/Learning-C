#include <stdio.h>

// This will likely be a simple exercise. All you would need to do is perform a dec > base conversion and append the result to a string
// Of course there is an issue with which characters to use, but you could just use some ASCII magic for that
// Loop through array, if character value is greater than 57, add 8

#define SIZE 200

void itob(int n, char s[], int b);

int main() {
    char output[SIZE];

    int n1 = 123;
    itob(n1, output, 16);
    printf("%s\n", output);

    int n2 = 1000;
    itob(n2, output, 2);
    printf("%s\n", output);

    int n3 = 364766;
    itob(n3, output, 27);
    printf("%s\n", output);

    int n4 = 29234652;
    itob(n4, output, 36);
    printf("%s\n", output);

    return 0;
}

void itob(int n, char s[], int b) {
    int remainders[SIZE];

    int i = 0;
    while (n > 0) {
        remainders[i++] = n % b;
        n = n / b;
    }

    int length = i;
    for (; i >= 0; --i) {
        if (remainders[i] > 9) {
            s[length - i - 1] = remainders[i] + 55;
        }
        else {
            s[length - i - 1] = remainders[i] + 48;
        }
    }
    s[length] = '\0';
}