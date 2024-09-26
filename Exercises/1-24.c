#include <stdio.h>

#define SIZE 3000

int main() {
	// Variables
	char input[SIZE];
	int pairs[SIZE];
	int length = 0;
	int pairCounter = 0;
	int inComment = 0;
	int imbalanceFound = 0;
	int sQuoteCount = 0;
	int dQuoteCount = 0;

	// Fill pairs array with 0
	int i;
	for (i = 0; i < SIZE; ++i) {
		pairs[i] = 0;
	}

	// Get input from the user
	int c;
	while ((c = getchar()) != EOF) {
		input[i] = c;
		++length;
	}

	// Scan through the input to see if it contains at least 1 error
	for (i = 0; i < length; ++i) {
		/*
		// Skip through comments
		if (input[i] == '/' && input[i + 1] == '/') {
			inComment = 1;
		}
		else if (input[i] == '/' && input[i + 1] == '*') {
			inComment = 1;
		}
		else if (input[i] == '\n') {
			inComment = 0;
		}
		else if (input[i] == '*' && input[i + 1] == '/') {
			inComment = 0;
			++i;
			++i;
		}
		*/

		// Find pairs
		if (inComment == 0) {
			// Opening
			if (input[i] == '(') {
				int j = 1;
				while (((input[i + j]) != ')' && (input[i + j]) != EOF) || ((input[i + j]) == ')' && pairs[i + j] != 0)) {
					++j;
				}
				if ((input[i + j]) == ')' && pairs[i + j] == 0) {
					++pairCounter;
					pairs[i] = pairCounter;
					pairs[i + j] = pairCounter;
				}
				else if ((input[i + j]) != EOF) {
					imbalanceFound = 1;
				}
			}
			// Closing
			else if (input[i] == ')' && pairs[i] == 0) {
				imbalanceFound = 1;
			}
			// Quotes
		}
	}

	// Print the results to the user
	printf("imbalanceFound = %d\n", imbalanceFound);
	if (imbalanceFound == 1 || sQuoteCount % 2 == 1 || dQuoteCount % 2 == 1) {
		printf("Program contains one or more errors.");
	}
	else {
		printf("Program contains no errors.");
	}

	return 0;
}