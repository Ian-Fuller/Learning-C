#include <stdio.h>

int main()
{
	int c;

	int blank = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != '\t')
			if (c != '\b')
				if (c != '\\')
					printf("%c", c);

		if (c == '\t')
			printf("\\t");
		if (c == '\b')
			printf("\\b");
		if (c == '\\')
			printf("\\\\");
	}
}