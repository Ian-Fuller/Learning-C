#include <stdio.h>

#define SIZE 20

int binsearch(int x, int v[], int n);

int main() {
    int v[SIZE];
    int i;
    for (i = 0; i < SIZE; i++) {
        v[i] = i;
    }

    printf("%d\n", binsearch(21, v, SIZE)); // -1
    printf("%d\n", binsearch(12, v, SIZE)); // 12
    printf("%d\n", binsearch(81, v, SIZE)); // -1
    printf("%d\n", binsearch(9, v, SIZE));  // 9
    printf("%d\n", binsearch(-7, v, SIZE)); // -1

    return 0;
}

// int binsearch(int x, int v[], int n) {
//     int low, mid, high;

//     low = 0;
//     high = n - 1;
//     while (low <= high) {
//         mid = (low + high) / 2;

//         if (x < v[mid]) {
//             high = mid - 1;
//         }
//         else if (x > v[mid]) {
//             low = mid + 1;
//         }
//         else {
//             return mid;
//         }
//     }

//     return -1;
// }

int binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0; // sets low to the lowest possible value, 0, since this function isn't designed to handle negatives
    high = n - 1; // sets high to the size of the array
    mid = (low + high) / 2; // sets mid to the average between low and high, rounding down because of data type truncation
    while (low <= high && x != v[mid]) { // exits loop once low exceeds high, meaning the value has not been found, or once x equals the value of the element in the array, meaning the value has been found
        if (x < v[mid]) { // the value of the element in the array is greater than the value to be found, so...
            high = mid - 1; // move the high value down; this also affects the calculation of the mid value
        }
        else { // the value of the element in the array is less than or equal to the value to be found, so...
            low = mid + 1; // move the low value up; this also affects the calculation of the mid value
        }

        mid = (low + high) / 2; // recalculate mid using the newly changed low or high value
    }
    if (x == mid) { // value has not been found
        return mid;
    }

    return -1; // value has been found
}