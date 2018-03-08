#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Maxsubsequencesum.h"

clock_t start, stop;
double duration;
#define MAXN 10
#define maxk 100000

int subarray[11] = { 1, 2, 3, 4, 5, 6, 7, 888, 9, 55, 16516 };

int main() {
    int result = 0;
    int i = 0;
    start = clock();

    for (i = 0; i < maxk; i++) {
        result = MaxSubsequenceSum(subarray, 10);
    }

    printf("the program runing times is %d. \nthe max subsequence is %d \n", maxk, result);
    stop = clock();
    duration = ((double) (stop - start)) / CLK_TCK;
    printf("ticks1 = %f\n", (double) (stop - start));
    printf("duration1 = %6.2e\n", duration);

    return 0;
}
