#include <stdio.h>

#define SIZE 2000

int getline(char line[]);

int main() {
	char line[SIZE / 10];
	char pool[SIZE];
	int i = 0;
	int j = 0;

	int length = 0;
	while ((length = getline(line)) != EOF) {
		if (length > 0) {
			for (j = 0; j < length; ++j) {
				pool[i] = line[j];
				++i;
			}
		}
		length = 0;
	}

	for (j = 0; j < i; ++j) {
		printf("%c", pool[j]);
	}
}

int getline(char line[]) {
	int localLine[SIZE / 10];
	int lastChar = 0;

	int i = 0; // also acts as the length of localLine
	int c;
	while ((c = getchar()) != '\n' && i < (SIZE / 10) - 1) {
		if (c == EOF) {
			return EOF;
		}

		localLine[i] = c;
		++i;
		
		if (c != ' ' && c != '\t') {
			lastChar = i;
		}
	}

	int onlyWS = 0;
	int j;
	for (j = 0; j < i; ++j) {
		if (localLine[j] != ' ' && localLine[j] != '\t') {
			onlyWS = 1;
		}
	}
	if (onlyWS == 0) {
		return 0;
	}

	if (c == '\n' && i > 0) {
		localLine[i] = c;
		++i;
		++lastChar;
	}

	for (i = 0; i < lastChar; ++i) {
		line[i] = localLine[i];
	}

	return lastChar;
}