#include <stdio.h>

#define SIZE 200

int getline(char line[]);

int main() {
	while (1 == 1) {
		char line[SIZE];
		char output[SIZE * 2];
		int limit = SIZE / 10;
		int length = getline(line);

		if (length > 1) {
			int current = 0;

			int i;
			int j = 0;
			for (i = 0; i < length; ++i) {
				if (current < limit) {
					output[j] = line[i];
					++current;
				}
				else {
					int diff = 0;
					while (line[i - diff] != ' ' && line[i - diff] != '\t') {
						++diff;
						output[j - diff] = ' ';
					output[j] = '\n';
					current = 0;
					}
				}
				++j;
			}
			length = j;
		}

		int i;
		for (i = 0; i < length; ++i) {
			printf("%c", output[i]);
		}
	}

	return 0;
}

int getline(char line[]) {
	int length;
	int c;

	int i = 0;
	while ((c = getchar()) != '\n') {
		line[i] = c;
		++length;
	}
	line[i] = c;
	++length;

	return length;
}