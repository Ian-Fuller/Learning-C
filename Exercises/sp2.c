#include <stdio.h>
#include <string.h>

#define SIZE 100

void increment(char *p[]);
void decrement(char *p[]);

void myFunc(char **array2d, char s[]);

int main()
{
    // char a = 'A';
    // char *p = &a;
    // char **pp = &p;
    // char **ppstart = pp;

    // printf("%c\n", **pp);

    // **pp++;
    // char b = 'B';
    // *pp = &b;

    // printf("%c\n", **pp);

    int i, j;
    char *array2d[SIZE];

    // for (i = 0; i < 2; i++) {
    //     char array1d[SIZE];

    //     for (j = 0; j < 10; j++) {
    //         array1d[j] = 65 + j;
    //     }
    //     array1d[j] = '\0';

    //     // char *p = array1d;
    //     *array2d = array1d;
    //     increment(array2d);
    // }

    // decrement(array2d);
    // decrement(array2d);

    char s1[] = "Hello, World!";
    char s2[] = "The quick brown fox jumped over the lazy dog.";
    myFunc(array2d, s1);
    myFunc(array2d, s2);
    decrement(array2d);
    decrement(array2d);
    // printf("%s\n", *array2d);
    increment(array2d);
    // printf("%s\n", *array2d);

    // for (i = 0; i < 2; i++) {
    //     printf("%s\n", *array2d);
    // }

    // for (i = 0; i < 2; i++) {
    //     char allocator = '_';
    //     char *array1d = &allocator;

    //     for (j = 0; j < 10; j++) {
    //         *array1d = 65 + j;
    //         array1d++;
    //     }
    //     *array1d = '\0';

    //     array1d -= j;
    //     printf("%s\n", array1d);
    //     char *p = array1d;
    //     array2d = &p;
    //     printf("%s\n", *array2d);
    //     array2d++;
    // }

    // array2d -= i;
    // for (i = 0; i < 10; i++) {
    //     printf("%c", *array2d[i]);
    // }

    printf("finised");

    // for(i = 0; i < 2; i++) {
    //     for (j = 0; j < 10; j++) {
    //         printf("%c", **array2d);
    //         *array2d++;
    //     }

    //     printf("\n");

    //     array2d++;
    // }

    return 0;
}

void increment(char **p) {
    p++;
}

void decrement(char **p) {
    p--;
}

void myFunc(char **array2d, char s[]) {
    array2d = &s;
    printf("%s\n", *array2d);
    array2d++;
    printf("%s\n", *array2d);
}