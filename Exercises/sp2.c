#include <stdio.h>
#include <string.h>

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
    char **array2d = {""};

    for (i = 0; i < 2; i++) {
        char allocator = '_';
        char *array1d = &allocator;
        // array2d = &array1d;

        for (j = 0; j < 10; j++) {
            *array1d = 65 + j;
            array1d++;
        }
        *array1d = '\0';

        array1d -= j;
        // array2d = &array1d;
        printf("%s\n", array1d);
        printf("%s\n", *array2d);
        array2d++;
    }

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