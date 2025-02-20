#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main () {
	// 201 - 11001001
	// 108 - 01101100
	// 209 - 11010001 (result)
	printf("%d\n", setbits(201, 4, 3, 108));

	return 0;
}

// get the rightmost n bits of y
// replace n bits in x, starting at p, with the n bits in y
int setbits(unsigned x, int p, int n, unsigned y) {
	unsigned xMaskL = ~0 << (p + 1);
	unsigned xMaskR = ~(~0 << (p + 1 - n));
	unsigned xMask = xMaskL | xMaskR;
	unsigned xMasked = x & xMask;

	unsigned yMask = ~(~0 << n);
	unsigned yMasked = y & yMask;
	unsigned yShifted = yMasked << (p + 1 - n);

	unsigned selection = xMasked | yShifted;

	return selection;
}

// x         = 11001001 - x
// xMaskL    = 11100000 - mask selecting everything to the left of p (4) (keep in mind these are indexed like an array, and start at the right)
// xMaskR    = 00000011 - mask selecting everything to the right of p (4) - n (3)
// xMask     = 11100011 - the left and right mask combined
// xMasked   = 11000001 - x with elements p through p - n erased

// y         = 01101100 - y
// yMask     = 00000111 - mask for the rightmost 3 bits
// yMasked   = 00000100 - the rightmost 3 bits of y
// yShifted  = 00010000 - the rightmost 3 bits of y shifted to the empty space in x

// selection = 11010001

// example equation taken from Richard Heathfield on penti.org
// return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));

// ~0 << (p + 1) creates a left-adjusted mask based on (p + 1)
// ~(~0 << (p + 1 - n)) creates a right-adjusted mask using the inversion of (p + 1 - n)
// the or (|) between the mask combines them
// lastly, the and (&) applies this combined mask to x

// ~(~0 << n) creates a rightmost mask based on the inverion of n
// the and (&) applies this mask to y
// p + 1 - n shifts y to the left
// the final or (|) combines the masked x and the shifted y

// (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n))
// (11001001 & ((~0 << (4 + 1)) | (~(~0 << (4 + 1 - 3))))) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// (11001001 & ((11111111 << 5) | (~(~0 << (4 + 1 - 3))))) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// (11001001 & (11100000 | (~(~0 << (4 + 1 - 3))))) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// (11001001 & (11100000 | (~(~0 << 2)))) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// (11001001 & (11100000 | (~(11111111 << 2)))) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// (11001001 & (11100000 | (~11111100))) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// (11001001 & (11100000 | 00000011)) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// (11001001 & 11100011) | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// 11000001 | ((01101100 & ~(~0 << 3)) << (4 + 1 - 3))
// 11000001 | ((01101100 & ~(11111111 << 3)) << (4 + 1 - 3))
// 11000001 | ((01101100 & ~11111000) << (4 + 1 - 3))
// 11000001 | ((01101100 & 00000111) << (4 + 1 - 3))
// 11000001 | (00000100 << (4 + 1 - 3))
// 11000001 | (00000100 << 2)
// 11000001 | 00010000
// 11010001