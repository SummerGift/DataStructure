// templatefunc.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

template <typename T>
void swap(T& a,T& b)
{
	T t = a;
	a = b;
	b = t;

}

template < typename T >
class  Operator
{
public:
	T process(T v)
	{
		return v * v;
	}

private:

};

namespace first_space {
	void func() {
		printf("Inside first_space\n");
	}
}

namespace second_space {
	void func() {
		printf("Inside second_space\n");
	}
}

int main()
{
	int a = 1;
	int b = 2;
	swap(a,b);
	printf("a:%d,b:%d.\n",a,b);

	double c = 0.01;
	double d = 0.02;
	swap(c,d);
	printf("c:%lf,d:%lf\n",c,d);

	Operator<int> opint;
	printf(" 5 * 5 = %d.\n",opint.process(5));
	Operator<double> opdouble;
	printf(" 5 * 5 = %lf.\n", opdouble.process(5));

	// 调用第一个命名空间中的函数
	first_space::func();

	// 调用第二个命名空间中的函数
	second_space::func();

    return 0;
}

