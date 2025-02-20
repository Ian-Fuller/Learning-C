#include <stdio.h>

#define SIZE 2000

int getbits(unsigned int x, int p, int n);

int main() {
	printf("%d\n", getbits(201, 0, 1));

	return 0;
}

int getbits(unsigned int x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}