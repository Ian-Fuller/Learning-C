#include <stdio.h>

int main()
{
	int lengths[100];
	int i, j;

	for (i = 0; i < 100; ++i)
		lengths[i] = 0;

	int inWord = 0;
	int wordLength = 0;
	int c = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ' && c != '\t' && c != '\n')
			++wordLength;
		else {
			++lengths[wordLength];
			wordLength = 0;
		}
	}

	printf("count | occurences\n");
	for (i = 0; i < 100; ++i)
	{
		if (lengths[i] != 0) {
			printf("%5d | ", i);
			for (j = 0; j < lengths[i]; ++j)
				printf("%c", 219);
			printf("\n");
		}
	}
}