#include <stdio.h>

int rightrot(unsigned x, int n);

int main() {
    // 201 - 11001001
    printf("%d\n", rightrot(201, 3)); // should print 57 (00111001)

    return 0;
}

// copy the area that will be pushed out by the rotation
// rotate x by n (right shift)
// shift the copied area by 8 - n
// combine the rotated x and the copied area
int rightrot(unsigned x, int n) {
    unsigned spill = x & ~(~0 << n);
    unsigned rotation = x >> n;
    spill = spill << (8 - n);

    return rotation | spill;
}