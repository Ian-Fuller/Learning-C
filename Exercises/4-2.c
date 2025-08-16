#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atofSN(char s[]);

int main() {
    char s1[] = "123.456";
    printf("%g\n", atofSN(s1));

    char s2[] = "-10.01";
    printf("%g\n", atofSN(s2));

    char s3[] = "+84.2";
    printf("%g\n", atofSN(s3));

    char s4[] = "   105";
    printf("%g\n", atofSN(s4));

    char s5[] = "123.45e-6";
    printf("%g\n", atofSN(s5));

    char s6[] = "-123.45E6";
    printf("%f\n", atofSN(s6)); // Uses %f instead of %g to disable scientific notation

    return 0;
}

double atofSN(char s[]) {

    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {

        i++;
        int signExp = 1;
        if (s[i] == '-') {
            signExp = -1;
            i++;
        }

        double exponent;
        for (exponent = 0.0; isdigit(s[i]); i++) {
            exponent = 10.0 * exponent + (s[i] - '0');
        }
        val = val * pow(10, exponent * signExp);
    }

    return sign * val / power;
}