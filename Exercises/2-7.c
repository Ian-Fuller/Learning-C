#include <stdio.h>

int invert(unsigned x, int p, int n);

int main () {
	// 201 - 11001001
	printf("%d\n", invert(201, 4, 3)); // should print 213 (11010101)

	return 0;
}

int invert(unsigned x, int p, int n) {
	unsigned maskEdges = (~0 << (p + 1)) | (~(~0 << (p + 1 - n)));
	unsigned maskCenter = ~maskEdges;
	unsigned unchanged = x & maskEdges;
	unsigned inverted = ~x & maskCenter;

	return unchanged | inverted;
}