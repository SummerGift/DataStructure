#include "stdafx.h"
#include "Operator.h"

namespace first_space{

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
}

namespace second_space {

	void swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = t;
	}
}

int main()
{
	int a = 1;
	int b = 2;
	//first_space::swap(&a, &b);
	//printf("a = %d,b =%d.\n",a,b);
	//second_space::swap(a, b);
	//printf("a = %d,b =%d.\n", a, b);

	const int& c = a;
	int *p = (int *)&c;
	*p = 5;
	printf("c = %d.",c);

	const int& d = 1;
	printf("d = %d.", d);


	return 0;
}