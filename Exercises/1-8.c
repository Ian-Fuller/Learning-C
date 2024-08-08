// Program will only count characters if the line contains a newline character

#include <stdio.h>

int main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++nl;
		if (c == '\t')
			++nl;
		if (c == '\n')
			++nl;
	}
	printf("\n%d\n", nl);
}