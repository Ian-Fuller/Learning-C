#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Integer ranges from library:\n");
    // char
    printf("\tChar:\n");
    printf("\t\tSigned: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("\t\tUnigned: %d to %d\n", 0, UCHAR_MAX);
    // short
    printf("\tShort:\n");
    printf("\t\tSigned: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("\t\tUnigned: %d to %d\n", 0, USHRT_MAX);
    // int
    printf("\tInt:\n");
    printf("\t\tSigned: %d to %d\n", INT_MIN, INT_MAX);
    printf("\t\tUnigned: %d to %u\n", 0, UINT_MAX);
    // long
    printf("\tLong:\n");
    printf("\t\tSigned: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("\t\tUnigned: %d to %lu\n", 0, ULONG_MAX);

    printf("Floating point ranges from library:\n");
    // float
    printf("\tFloat: %f to %f\n", FLT_MIN, FLT_MAX);
    // double
    printf("\tDouble: %lf to %lf\n", DBL_MIN, DBL_MAX);

    printf("Integer ranges from computation:\n");
    // char
    printf("\tChar:\n");
    printf("\t\tSigned: %d to %d\n", -1 << 7, (1 << 7) - 1);
    printf("\t\tUnigned: %d to %d\n", 0, 1 << 8);
    // short
    printf("\tShort:\n");
    printf("\t\tSigned: %d to %d\n", -1 << 15, (1 << 15) - 1);
    printf("\t\tUnigned: %d to %d\n", 0, 1 << 16);
    // int
    printf("\tInt:\n");
    printf("\t\tSigned: %d to %d\n", -1 << 31, (1 << 31) - 1);
    printf("\t\tUnigned: %d to %u\n", 0, 1 << 32);
    // long
    printf("\tLong:\n");
    printf("\t\tSigned: %ld to %ld\n", -1 << 31, (1 << 31) - 1);
    printf("\t\tUnigned: %d to %lu\n", 0, 1 << 32);

    printf("Floating point ranges from computation:\n");
    // float
    printf("\tFloat: %f to %f\n", FLT_MIN, FLT_MAX);
    // double
    printf("\tDouble: %lf to %lf\n", DBL_MIN, DBL_MAX);

    return 0;
}