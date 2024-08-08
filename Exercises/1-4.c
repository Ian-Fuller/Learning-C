#include <stdio.h>

int main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = -20;
	upper = 160;
	step = 20;

	celsius = lower;
	while (celsius <= upper)
	{
		fahr = celsius / (5.0/9.0) + 32.0;
		printf("%5.1f %4.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}