#include <stdio.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; } // curly braces added to reduce the scope of temp

int main() {
    int ten = 10;
    int eleven = 11;
    int twelve = 12;
    int thirteen = 13;
    char alpha = 'a';
    char beta = 'b';

    swap(int, ten, eleven);
    printf("ten: %d\n", ten);
    printf("eleven: %d\n", eleven);

    swap(int, twelve, thirteen);
    printf("twelve: %d\n", twelve);
    printf("thirteen: %d\n", thirteen);

    swap(char, alpha, beta);
    printf("alpha: %c\n", alpha);
    printf("beta: %c\n", beta);

    return 0;
}