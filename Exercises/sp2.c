#include <stdio.h>

int main() {
	char str1[] = "cat\0";
	char str2[] = "ibex\0";
	char str3[] = "elephant\0";
	char str4[] = "penguin\0";
	char str5[] = "eel\0";
	printf("%s%s%s%s%s", str1, str2, str3, str4, str5);
}