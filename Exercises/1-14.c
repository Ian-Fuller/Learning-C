#include <stdio.h>

#include <stdio.h>

int main()
{
	int count[256];
	int i, j;

	for (i = 0; i < 256; ++i)
		count[i] = 0;

	int c = 0;
	while ((c = getchar()) != EOF)
	{
		++count[c];
	}

	printf("char | occurences\n");
	for (i = 0; i < 256; ++i)
	{
		if (count[i] != 0) {
			printf("%4c | ", i);
			for (j = 0; j < count[i]; ++j)
				printf("%c", 219);
			printf("\n");
		}
	}
}

// Count the occurences of each character in this sentence.