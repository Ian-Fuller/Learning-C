#include <stdio.h>

#define SIZE 2000



int main() {

char input[SIZE];
char output[SIZE];
int  c;
int length = 0;


while ((c = getchar()) != EOF) {
input[length] = c;
++length;
}


int i;
int j = 0;
for (i = 0; i < length; ++i) {
if (input[i] == '/') {
if (input[i + 1] == '/') {
while(input[i] != '\n') {
++i;
}

}
else if (input[i + 1] == '*') {
while(!(input[i] == '*' && input[i + 1] == '/')) {
++i;
}
++i;
++i;
if (input[i] == '\n') {

}
}
}

output[j] = input[i];
++j;
}


for (i = 0; i < j; ++i) {
printf("%c", output[i]);
}

return 0;
}