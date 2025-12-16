#include <stdio.h>

char nums[2][5] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9}
};

int main() {
    char *numsp = nums;

    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", *numsp++);
    }

    return 0;
}