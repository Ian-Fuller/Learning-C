#include <stdio.h>

#define SIZE 200

void expand(char s1[], char s2[]);

int main() {
    char s1[SIZE] = "-14 a-z, A-G-Y, 0-9!";
    char s2[SIZE] = "";

    printf("%s%s\n", "Expand this: ", s1);

    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

// look for hyphens
// if one is found, look further to the right for additional hyphens
// calculate the range between the smallest and largest values in the hyphen chain
// add the range to the string
void expand(char s1[], char s2[]) {
    int i, j;
    for (i = 0, j = 0; s1[i] != '\0'; i++, j++) {
        if (s1[i+1] == '-') { // adjacent character needs to be checked so the first element of the abbreviation isn't left in
            char first = s1[i];
            char last = s1[i];
            if (first != ' ') { // If the hyphen is in between two charatcers, rather than in front, in the case of a negative number, etc.
                int k;
                for (k = 2; 1; k += 2) { // 1 = true; loop runs until broken
                    char left = s1[i + k - 1];
                    char right = s1[i + k];
                    if (left == '-' && 
                        (right >= 'a' && right <= 'z' ||
                        right >= 'A' && right <= 'Z' ||
                        right >= '0' && right <= '9')
                    ) {
                        last = right;
                    }
                    else {
                        break;
                    }
                }

                i += k; // needed so the main loop doesn't iterate over different portions of the same abbreviation segment

                for (k = first; k <= last; k++, j++) {
                    s2[j] = k;
                }
                s2[j] = ' '; // this is needed so that s2[j] isn't equal to '\0', which will cause the string to get cut off while printing
            }
            else {
                s2[j] = s1[i];
            }
        }
        else {
            s2[j] = s1[i];
        }
    }
}