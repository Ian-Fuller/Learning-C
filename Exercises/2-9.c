#include <stdio.h>

// The expression [x &= (x-1)] deletes the rightmost bit in x because
// it subtracts 1 from x, making the first bit 0. When & is used on x
// and x-1, all bits will equal true (1) except for bit 0, which will
// be false (0).

int bitcount(unsigned x);

int main() {
    // 201d = 11001001b
    printf("%d\n", bitcount(201)); // should print 4

    return 0;
}

int bitcount(unsigned x) {
    int b;

    // if x is odd (has a 1 in its least significant bit), it will be
    // subtracted normally and the &= will remove it from x
    // if x is even, subtracting it by 1 will replace the rightmost 1
    // with 0, and all of the bits to the right of it will become 1.
    // This means that if &= is applied to it, the rigtmost 1 and all
    // of the bits next to it will be replaced with 0
    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }
    // x = 11001001 & (11001001 - 1)
    // x = 11001001 & 11001000
    // x = 11001000

    // x = 11001000 & (11001000 - 1)
    // x = 11001000 & 11000111
    // x = 11000000

    // x = 11000000 & (11000000 - 1)
    // x = 11000000 & 10111111
    // x = 10000000

    // x = 10000000 & (10000000 - 1)
    // x = 10000000 & 01111111
    // x = 00000000

    return b;
}