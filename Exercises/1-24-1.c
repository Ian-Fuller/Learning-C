/*
This exercise has proven to be rather difficult, so I have abandoned this code to learn a new solution.
I decided to learn by example from examining other people's code.
*/

#include <stdio.h>

#define SIZE 3000

int main() {
	// Variables
	char input[SIZE];
	int pairs[SIZE];
	int length = 0;
	int pairCounter = 0;
	int inComment = 0;
	int inQuote = 0;
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
	i = 0;
	while ((c = getchar()) != EOF) {
		input[i] = c;
		++i;
		++length;
	}

	// Scan through the input to see if it contains at least 1 error
	int nlCounter = 0;
	for (i = 0; i < length; ++i) {
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

		// Skip through quotes
		if (inComment == 0) {
			if ((input[i] == '\'' || input [i] == '\"') && inQuote == 0) {
				//printf("Entered quote (Ln: %d) [%d]\n", nlCounter, i); // Program stops at the first parenthesis
				inQuote = 1;
			}
			else if ((input[i] == '\'' || input [i] == '\"') && inQuote == 1) {
				//printf("Exited quote (Ln: %d) [%d]\n", nlCounter, i);
				inQuote = 0;
			}
		}

		// Find pairs
		// Opening
		if (input[i] == '(') { // Program finds a parenthesis inside a comment, then stops
			int j = 1;
			while (								// Continue incrementing as long as...
				(input[i + j]) != ')' && (input[i + j]) != EOF		// A closing character HAS NOT been found and the end of the file has not been reached
				|| (input[i + j]) == ')' && pairs[i + j] != 0		// A closing character HAS been found, but it has already been assigned to a pair
				|| inComment == 1					// The loop is currently in a comment
				|| inQuote == 1						// The loop is currently in a quote
			) {
				// Comment detection
				if (input[i + j] == '/' && input[i + j + 1] == '/') {
					inComment = 1;
				}
				else if (input[i + j] == '/' && input[i + j + 1] == '*') {
					inComment = 1;
				}
				else if (input[i + j] == '\n') {
					inComment = 0;
				}
				else if (input[i + j] == '*' && input[i + j + 1] == '/') {
					inComment = 0;
				}
				
				// Quote detection
				if (inComment == 0) {
					if ((input[i] == '\'' || input [i] == '\"') && inQuote == 0) {
						inQuote = 1;
					}
					else if ((input[i] == '\'' || input [i] == '\"') && inQuote == 1) {
						inQuote = 0;
					}
				}

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
		else if (input[i] == ')' /*&& pairs[i] == 0*/) {
			printf("Character: %c, Pair: %d, Line: %d [%d]\n", input[i], pairs[i], nlCounter, i);
			imbalanceFound = 1;
		}
		// Quotes
		if (input[i] == '\n')
			++nlCounter;
		printf("%c", input[i]);
	}

	// Print the results to the user
	if (imbalanceFound == 1 || sQuoteCount % 2 == 1 || dQuoteCount % 2 == 1) {
		printf("Program contains one or more errors.");
	}
	else {
		printf("Program contains no errors.");
	}

	return 0;
}