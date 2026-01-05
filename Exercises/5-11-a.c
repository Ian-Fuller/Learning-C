#include <stdio.h>

#define SIZE 200

int getline(char line[]);
int getlongest(char line[]);

int main(int argc, char *argv[]) {
	while (1) {
		char line[SIZE];
		int length = 0;

		length = getline(line);

		int tabSpaces = getlongest(line);

		int i;
		int occupied = 0;
		for (i = 0; i < length; ++i) {
            int argcStart = argc;
			char **argvStart = argv;
            while (--argc > 0) {
                if (i == (int)((*++argv)[0]) - 48) {
					int j;
					for (j = 0; j <= tabSpaces - occupied; ++j) {
						printf(" ");
					}
					occupied = 0;
                }
            }
			argc = argcStart;
			argv = argvStart;

			if (line[i] != '\t') {
				printf("%c", line[i]);
				++occupied;
			}
			else {
				int j;
				for (j = 0; j <= tabSpaces - occupied; ++j) {
				    printf(" ");
				}
				occupied = 0;
			}
		}
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
	++length;

	return length;
}

int getlongest(char line[]) {
	int current = 0;
	int longest = 0;

	int i = 0;
	while (line[i] != '\n') {
		if (line[i] != ' ' && line[i] != '\t') {
			++current;
		}
		else {
			current = 0;
		}

		if (current > longest) {
			longest = current;
		}

		++i;
	}

	return longest;
}