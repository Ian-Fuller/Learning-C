#include <stdio.h>

#define SIZE 2000

/* This program contains extra comments
inside it to test its own functionality */

int main() {
	// variable declaration
	char input[SIZE];
	char output[SIZE];
	int /* ignore this */ c;
	int length = 0;

	// get user input
	while ((c = getchar()) != EOF) {
		input[length] = c;
		++length;
	}

	// scan through the input to skip over comments
	int i;
	int j = 0;
	for (i = 0; i < length; ++i) {
		if (input[i] == '/') { // the beginning of a comment has been located
			if (input[i + 1] == '/') { // the comment is single-line
				while(input[i] != '\n') {
					++i;
				}
			}
			else if (input[i + 1] == '*') { // the comment is multi-line
				while(!(input[i] == '*' && input[i + 1] == '/')) { // while the comment has not ended
					++i;
				}
				++i;
				++i;
			}
		}

		output[j] = input[i];
		++j;
	}

	// output
	for (i = 0; i < j; ++i) {
		printf("%c", output[i]);
	}

	return 0;
}