/*
Taken from Rick Dearman's example on penti.org
Program works for the most part, but characters inside comments and quotes are still counted, which doesn't exaclt solve the problem.
*/

// To counter the program's own mismathes: " '

#include <stdio.h>

#define MAXLINE 3000
char line[MAXLINE];

int getline(void);

int main() {
	int len = 0;
	int t = 0;
	int brace = 0, bracket = 0, paren = 0;
	int sQuote = 1, dQuote = 1;

	while ((len = getline()) > 0) {
		t = 0;
		while (t < len) {
			if (line[t] == '[') {
				bracket++;
			}
			if (line[t] == ']') {
				bracket--;
			}
			if (line[t] == '{') {
				brace++;
			}
			if (line[t] == '}') {
				brace--;
			}
			if (line[t] == '(') {
				paren++;
			}
			if (line[t] == ')') {
				paren--;
			}
			if (line[t] == '\'') {
				sQuote *= -1;
			}
			if (line[t] == '\"') {
				dQuote *= -1;
			}
			t++;
		}
	}

	int errorFound = 0;
	if (sQuote != 1) {
		printf("Mismatching single quotes\n");
		errorFound = 1;
	}
	if (dQuote != 1) {
		printf("Mismatching double quotes\n");
		errorFound = 1;
	}
	if (paren != 0) {
		printf("Mismatching parentheses\n");
		errorFound = 1;
	}
	if (bracket != 0) {
		printf("Mismatching brackets\n");
		errorFound = 1;
	}
	if (brace != 0) {
		printf("Mismatching braces\n");
		errorFound = 1;
	}
	if (errorFound == 0) {
		printf("No mismatching characters\n");
	}

	return 0;
}

int getline(void) {
	int c, i;
	extern char line[];

	for (
		i = 0;
		i < MAXLINE - 1
		&& (c = getchar()) != EOF
		&& c != '\n';
		++i
	) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}