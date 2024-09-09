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
					++j;
					++current;
				}
				else {
					int diff = 0;
					while (line[i - diff] != ' ' && line[i - diff] != '\t') {
						output[j - diff] = ' ';
						++diff;
					}
					output[j] = '\n';
					while (diff >= 0) {
						++j;
						--diff;
						output[j] = line[i - diff];
					}
					current = 0;
				}
			}
			length = j;
		}

		int i;
		for (i = 0; i < length; ++i) {
			printf("%c", output[i]);
		}
		printf("\n");
	}

	return 0;
}

int getline(char line[]) {
	int length = 0;
	int c;

	while ((c = getchar()) != '\n') {
		line[length] = c;
		++length;
	}
	line[length] = c;

	return length;
}