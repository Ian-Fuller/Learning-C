/*
Based on Stefan Farfelder's example on penti.org
This program includes keywords that have not been introduced to the reader yet in the textbook, but it has full fonctionality.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 3072

enum {
	CODE,
	COMMENT,
	QUOTE1,
	QUOTE2,
};

int main() {
	int c;
	int state = CODE;
	char stack[MAX_STACK];
	size_t top = 0;
	size_t line = 1;
	int error = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			line++;
		}

		switch (state) {
		case CODE:
			// detect quotes
			if (c == '\'') {
				state = QUOTE1;
			}
			else if (c == '"') {
				state = QUOTE2;
			}
			// detect comments
			else if (c == '/') {
				int second = getchar();
				if (second == '*') {
					state = COMMENT;
				}
				else {
					ungetc(second, stdin);
				}
			}
			// detect opening characters
			else if (c == '(' || c == '[' || c == '{') {
				if (top < MAX_STACK) {
					stack[top++] = c;
				}
				else {
					printf("Stack too small!\n");
					return EXIT_FAILURE;
				}
			}
			// detect closing characters
			else if (c == ')' || c == ']' || c == '}') {
				if (top == 0) {
					error = 1;
				}
				else {
					char open = stack[--top];
					if (
						(c == ')' && open != '(') ||
						(c == ']' && open != '[') ||
						(c == '}' && open != '{')
					) {
						error = 1;
					}
				}
			}

			break;
		case COMMENT: // See if a comment can be exited
			if (c == '*') {
				int second = getchar();
				if (second == '/') {
					state = CODE;
				}
				else {
					ungetc(second, stdin);
				}
			}

			break;
		case QUOTE1: // See if a single quote can be exited
			if (c == '\\') {
				(void)getchar();
			}
			else if (c == '\'') {
				state = CODE;
			}

			break;
		case QUOTE2: // See if a double quote can be exited
			if (c == '\\') {
				(void)getchar();
			}
			else if (c == '"') {
				state = CODE;
			}

			break;
		}
	}

	if (top == 0 && error == 0 && state == CODE) {
		printf("Code is fine.\n");
	}
	else {
		printf("Code contains one or more errors.\n");
	}

	return 0;
}