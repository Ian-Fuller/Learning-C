#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	char line[MAXLINE];
	char longest[MAXLINE];

	int len;
	int max;

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("%s\n", longest);
		printf("Line length: %d\n", max);
	}
	return 0;
}

int getline(char s[], int lim) {
	int c, i;
	int j = 0;

	for (i = 0;
	     (c = getchar()) != EOF
	     && c != '\n';
	     ++i) {
		if (i < lim)
			s[i] = c;
		else
			++j;
	}
	if (c == '\n') {
		s[i - j] = c;
		++i;
	}
	s[i - j] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i;

	i = 0;
	for (i = 0; i < MAXLINE; ++i)
		to[i] = from[i];
}