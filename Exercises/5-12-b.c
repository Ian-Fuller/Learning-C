#include <stdio.h>

#define SIZE 200

int getline(char line[]);
int getlongest(char line[]);

int main(int argc, char *argv[]) {
	int start = 0;
	int every = 0;
	if (argc >= 3) {
		if ((*++argv)[0] == '-') {
			start = (*argv)[1] - '0';
		}
		if ((*++argv)[0] == '+') {
			every = (*argv)[1] - '0';
		}
		--argv;
		--argv;
	}

	while (1) {
		char line[SIZE];
		int length = 0;

		length = getline(line);

		int tabSpaces = getlongest(line);

		int i;
		int wordLength = 0;
		int skip = 0;
		for (i = 0; i < length; ++i) {
            int argcStart = argc;
			char **argvStart = argv;
            while (--argc > 0) {
                if (i == (int)((*++argv)[0]) - 48) {
					if (skip == 0) {
						int j;
						for (j = 0; j <= tabSpaces - wordLength; ++j) {
							printf(" ");
						}
						wordLength = 0;
						skip = 1;
					}
                }
            }
			argc = argcStart;
			argv = argvStart;

			if (start > 0 && every > 0) {
				if (i >= start && (i - start) % every == 0) {
					printf("\t");
				}
			}

			if (line[i] != ' ' && line[i] != '\t') {
				printf("%c", line[i]);
				++wordLength;
				skip = 0;
			}
			else {
				if (skip == 0) {
					int j;
					for (j = 0; j <= tabSpaces - wordLength; ++j) {
						printf(" ");
					}
					wordLength = 0;
					skip = 1;
				}
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