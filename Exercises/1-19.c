#include <stdio.h>

#define SIZE 200

void reverse(char s[], int length);

int main() {
	char line[SIZE];
	int c = 0;

	while (c != EOF) {
		int i = 0;
		while ((c = getchar()) != '\n' && c != EOF) {
			line[i] = c;
			++i;
		}

		reverse(line, i);
		
		int j;
		for (j = 0; j < i; ++j) {
			printf("%c", line[j]);
		}
		printf("\n");
	}
}

void reverse(char s[], int length) {
	char reversed[length];
	
	int i;
	for (i = 0; i < length; ++i) {
		reversed[i] = s[length - 1 - i];
	}
	for (i = 0; i < length; ++i) {
		s[i] = reversed[i];
	}
}
