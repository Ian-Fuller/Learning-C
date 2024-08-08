#include <stdio.h>

#define SIZE 2000
#define MIN 80

int getline(char line[]);

int main() {
	char line[SIZE / 10];
	char aggr[SIZE];

	int length = 0;
	int i = 0;
	int j;
	
	while ((length = getline(line)) > 1) {
		if (length > MIN) {
			j = 0;
			while (j < length) {
				aggr[i] = line[j];
				++i;
				++j;
			}
		}
	}
	
	printf("These lines are longer than %d characters: \n", MIN);
	for (j = 0; j < i; ++j) {
		printf("%c", aggr[j]);
	}

	return 0;
}

int getline(char line[]) {
	int i = 0;
	int c;
	while ((c = getchar()) != '\n' && i < (SIZE / 10) - 1) {
		line[i] = c;
		++i;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}