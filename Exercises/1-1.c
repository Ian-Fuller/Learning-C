#include <stdio.h>                // if excluded, the compiler says that 'printf' has been attempted to be declared implicitly, and that it either needs to be given a declaration, or <stdio.h> needs to be included

int main()                        // warning: type specifier 'int' is missing // if excluded, the compiler says it expects an identifier or '('
{                                 // if excluded, the compiler says that it expects a function body after the function declarator
	printf("hello, world\n"); // if excluded, the program does not output any text
}                                 // if excluded, the compiler expects '}'