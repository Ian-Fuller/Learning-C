#include <stdio.h>

#define SIZE 2000

int main() {
	int a = 1;
	if (a == 0) {
		printf("Print this out");
		a = 1;
	}
	else if (a == 1) {
		printf("Print this out as well");
		a = 0;
	}
}