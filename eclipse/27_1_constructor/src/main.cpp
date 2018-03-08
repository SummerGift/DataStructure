#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;
#define MAXN 10

double f1(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++)
        p += (a[i] * pow(x, i));
    return p;
}

double f2(int n, double a[], double x) {
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
}

int MaxSubsequenceSum(const int A[], int n) {
    int thissum, maxsum, i, j, k;

    maxsum = 0;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++) {
            thissum = 0;
            for (k = i; k <= j; k++) {
                thissum += A[k];
            }

            if (thissum > maxsum)
                maxsum = thissum;
        }

    return maxsum;
}

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
