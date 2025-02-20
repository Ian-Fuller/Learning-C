#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main() {
	printf("%d\n", getbits(15, 4, 4));
}

unsigned getbits(unsigned x, int p, int n) {
	int rShift = p + 1 - n;
	if (rShift < 0) {
		rShift = 0;
	}

	int bitMask = ~(~0 << n);
	
	return (x >> rShift) & bitMask;
}