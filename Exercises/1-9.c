#include <stdio.h>

int main()
{
	int c;

	int blank = 0;
	while ((c = getchar()) != EOF)
	{
		if (blank == 0)
			printf("%c", c);
		if (blank == 1)
			if (c != ' ')
				printf("%c", c);

		if (c == ' ')
			blank = 1;
		if (c != ' ')
			blank = 0;
	}
}

//Help,   I  think I       typed  too many                 spaces!