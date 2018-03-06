#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;
#define MAXN 10
#define maxk 10000000

double f1( int n, double a[], double x )
{
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++ )
	p += (a[i] * pow(x, i));
	return p;
}

double f2( int n, double a[], double x )
{
	int i;
	double p = a[n];
	for ( i=n; i>0; i-- )
	p = a[i-1] + x*p;
	return p;
}

int main ()
{
	int i;
	double a[MAXN];     /* 存储多项式的系数 */
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i;
	start = clock();
	for( i=0; i<maxk; i++)
	{
		f1(MAXN-1, a, 1.1);
	}

	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);

	start = clock();

	for( i=0; i<maxk; i++)
	{
		f2(MAXN-1, a, 1.1);
	}

	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("duration2 = %6.2e\n", duration);
	return 0;
}
